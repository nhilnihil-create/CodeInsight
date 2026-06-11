#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string t;
  cin>>t;
  for(char c:t){
    if(c=='?') cout<<'D';
    else cout<<c;
  }
  cout<<endl;
}