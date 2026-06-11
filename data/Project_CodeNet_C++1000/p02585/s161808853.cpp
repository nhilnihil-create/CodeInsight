#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <bitset>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> P(n);
    vector<int> C(n);
    for(int i=0;i<n;i++) cin >> P[i];
    for(int i=0;i<n;i++) cin >> C[i];
    for(int i=0;i<n;i++) P[i]--;
    ll ans=-1e18;
    for(int i=0;i<n;i++){
        int ind=i;
        vector<ll> cycle_cum;
        while(true){
            ind=P[ind];
            ll num=C[ind];
            if(cycle_cum.size()!=0) num+=cycle_cum.back();
            cycle_cum.push_back(num);
            if(ind==i) break;
        }
        ll cycle_sum=cycle_cum.back();
        int cycle_size=cycle_cum.size();
        if(cycle_sum<=0){
            for(int j=0;j<min(k,cycle_size);j++){
                ans=max(ans,cycle_cum[j]);
            }
        }else{
            ll tmp=cycle_sum;
            for(int j=0;j<k%cycle_size;j++){
                tmp=max(tmp,cycle_sum+cycle_cum[j]);
            }
            sort(cycle_cum.begin(),cycle_cum.end());
            ll sep=max(cycle_cum.back(),tmp);
            sep+=cycle_sum*(k/cycle_size-1);
            ans=max(ans,sep);
        }
    }
    cout << ans << endl;
}