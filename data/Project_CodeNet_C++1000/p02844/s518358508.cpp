#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(int i = 0; i <= 9; i++){
    for(int j = 0; j <= 9; j++){
      for(int k = 0; k <= 9; k++){
        queue<int> q;
        q.push(i);
        q.push(j);
        q.push(k);
        rep(si,n){
          if(s[si]=='0'+q.front()) q.pop();
          if(q.empty()){
            ans++;
            break;
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}

