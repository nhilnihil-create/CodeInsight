#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,d,i;cin >> n >> a >> b >> c >> d;
  a--;b--;c--;d--;
  char m[n+1];m[n] = '#';
  for(i=0;i<n;i++) cin >> m[i];
  if(c==d){
    cout << "No\n";return 0;
  }
  for(i=a;i<c;i++){
    if(m[i] == '#' && m[i+1] == '#'){
      cout << "No\n";return 0;
    }
  }
  for(i=b;i<d;i++){
    if(m[i] == '#' && m[i+1] == '#'){
      cout << "No\n";return 0;
    }
  }
  if(c<d){
    cout << "Yes\n";return 0;
  }
  for(i=b;i<min(c,d+1);i++){
    if(m[i-1]=='.' && m[i]=='.' && m[i+1]=='.'){
      cout << "Yes\n";return 0;
    }
  }
  cout << "No\n";return 0;
}