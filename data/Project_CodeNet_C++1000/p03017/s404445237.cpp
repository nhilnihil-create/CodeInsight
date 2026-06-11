#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  s = '#' + s + '#';
  for(int i=a;i<c;i++){
    if(s[i]=='#' && s[i+1]=='#'){
      cout << "No" << endl;
      return 0;
    }
  }
  for(int i=b;i<d;i++){
    if(s[i]=='#' && s[i+1]=='#'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(c < d){
    cout << "Yes" << endl;
    return 0;
  }
  for(int i=b;i<=d;i++){
    if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}