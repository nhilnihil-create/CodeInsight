#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  string s;
  cin>>s;

  int sum=0;
  rep(i,s.size()){
    sum+=s[i]-'0';
  }
  
  if(sum%9) puts("No");
  else puts("Yes");
  return 0;
}
