#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  100012101;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
 


int main(){
ll ans=0;
ll N,K;
cin>>N>>K;
rep4(i,K,N+1){
    ans+=N*(N+1)/2-(N-i+1)*(N-i)/2-i*(i-1)/2+1;
    ans%=(ll)powl(10,9)+7;
}
cout<<ans<<endl;
return 0;
}