#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int now = 1;
  int ans = 0;
  int N; cin >> N;

  for(int i = 0; i < N; i++){
    int tmp; cin >> tmp;
    if(tmp != now){
      ans++;
    } else { 
      now++;
    }
  }

  if(ans == N){
    ans = -1;
  }
  cout << ans << endl;
}
