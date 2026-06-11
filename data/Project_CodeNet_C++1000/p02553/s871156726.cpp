//-fexec-charset=CP932
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using p=pair<int,int>;
#define MAX 100
#define THOU 1000
#define FIVEMAX 100000
#define NINEMAX 1000000000
#define TWEMAX 1000000000000
#define rep(i,n) for (int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define darep(i,a,n) for(int i=n,i>=a;i--)
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
int main(){
 cin.tie(0);
 ios::sync_with_stdio(false);
 ll a,b,c,d;
 cin>>a>>b>>c>>d;
 vector<ll>v;

 v.push_back(a*c);
 v.push_back(a*d);
 v.push_back(b*c);
 v.push_back(b*d);
 sort(v.begin(),v.end());
 cout<<v.at(3);
 return 0;
}