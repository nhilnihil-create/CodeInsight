#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
   int n;
   cin >> n;
   vector<int> w(n);
   rep(i,n)cin>>w[i];
   //sort(w.begin(),w.end());
   rep(i,n-1) w[i+1]+=w[i];
   int MIN=1e6;
   rep(i,n-1){
       if(abs(w[i]-(w[n-1]-w[i]))<MIN)MIN=abs(w[i]-(w[n-1]-w[i]));
   }
   cout<<MIN<<endl;
}
