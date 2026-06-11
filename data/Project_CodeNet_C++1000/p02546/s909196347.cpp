#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
const ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  if(s[n-1]=='s') cout<<s<<"es"<<endl;
  else cout<<s<<"s"<<endl;
}