#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 0;
  rep(i,N){
    if(i!=0){
      ans += (N-1)/i;
      //cout << ans << endl;
    }
  }
  cout << ans << endl;
}