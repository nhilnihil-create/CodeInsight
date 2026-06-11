#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  rep(i,h){
    if(i < b){
      rep(j,w){
        if(j < a) cout << 1 ;
        else cout << 0;
      }
    }else{
      rep(j,w){
        if(j < a) cout << 0;
        else cout << 1;
      }
    }
    cout << endl;
  }

  return 0;
}



