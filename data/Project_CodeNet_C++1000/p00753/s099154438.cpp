#include <bits/stdc++.h>
#define REP(a,b,c) for(int a=b; a<(int)c; a++)
#define REPE(a,b,c) for(int a=b; a<=(int)c; a++)
#define REPD(a,b,c) for(int a=b; a>=(int)c; a--)
#define rep(a,b) REP(a,0,b)
#define repd(a,b) REPD(a,b,0)
typedef long long int ll;
using namespace std;

int main(){
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;
    int num = n + 1;
    int ans = 0;
    REPE(i,num,n*2){
      bool flag = false;
      for(int j=2; (j*j)<=i; j++){
        if((i%j) == 0){
          flag = true;
          break;
        }
      }
      if(!flag){
        // cout << i << endl;
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}