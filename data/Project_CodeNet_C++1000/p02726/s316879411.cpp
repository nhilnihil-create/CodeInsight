#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    ll n,x,y;
    cin>>n>>x>>y;
    x--; y--;
    vector<ll> ans(n,0);
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            if(i<=x && j<=x){
                ans[j-i-1]++;
            }else if(i<=x && j>=x & j<=y){
                ll now=min(j-i,x-i+1+y-j);
                ans[now-1]++;
            }else if(i<=x && j>=y){
                ans[j-y+x-i]++;
            }else if(i>=x && i<=y && j>=y){
                ll now=min(j-i,j-y+1+i-x);
                ans[now-1]++;
            }else if(i>=x && i<=y && j>=x && j<=y){
                ll now=min(j-i,y-j+1+i-x);
                ans[now-1]++;
            }else{
                ans[j-i-1]++;
            }
        }
    }
    for(ll i=0;i<n-1;i++){
        cout<<ans[i]<<endl;
    }
}