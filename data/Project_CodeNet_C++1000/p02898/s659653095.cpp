#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,K; cin >> N >> K;
  int ans = 0;
  for(int i = 0; i< N ; i++){
    int tmp; cin >> tmp;
    if(tmp >= K) ans++;
  }
  cout << ans << endl;
}
