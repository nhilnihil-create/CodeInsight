#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

map<ll,ll> get_div_factor(ll A){
    map<ll,ll> mp;
    ll B=A;
    for(ll i=2;i<=sqrt(A);i++){
        while(B%i==0){
            B /= i;
            mp[i] += 1;
        }
    }
    if(B!=1) mp[B]++;
    return mp;
}

int main(){
    ll A,B;
    cin >> A >> B;
    map<ll,ll> mpa, mpb;
    mpa = get_div_factor(A);
    mpb = get_div_factor(B);
   
    ll ans=0;
    for(auto p:mpa){
        if(mpb[p.first]!=0) ans+=1;
    }
    ans+=1;
    cout << ans << endl;
}