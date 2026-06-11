#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;

  int ans = 0;
  int min_val = 1000000;
  for(int i = 0; i < N; i++){
    int tmp; cin >> tmp;
    if(tmp <= min_val){
      ans++;
    }
    min_val = min(min_val, tmp);
  }
  cout << ans << endl;
}
