#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  string s;
  cin>>s;
  if(s.size()%2){
    cout<<"No";
  }else{
    bool f=false;
    for(int i=0;i<s.size();i+=2){
      if(s[i]!='h'||s[i+1]!='i'){
        f=true;
      }
    }
    if(f)cout<<"No";
    else cout<<"Yes";
  }
}