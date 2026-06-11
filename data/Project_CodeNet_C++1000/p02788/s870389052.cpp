#include <bits/stdc++.h>
using namespace std;

long long INF=pow(10LL, 16LL);

int main(){
  long N, D, A;
  cin >> N >> D >> A;
  
  pair<long, long> monsters[N]; //place, hp
  for (int i = 0; i < N; i++) {
    long X, H;
    cin >> X >> H;
    monsters[i]={X,H};
  }
  sort(monsters, monsters+N);
  
  long comulativeDamage = 0L;
  long ans = 0L;
  queue<pair<long, long>> q; //maximumRange, Damage
  for (int i = 0; i < N; i++) {
    
    long x = monsters[i].first;
    long hp = monsters[i].second;

    long decreaseDamage = 0;
    while (!q.empty()){
      if (x <= q.front().first) break;
      decreaseDamage += q.front().second;
      q.pop();
    }
    
    comulativeDamage -= decreaseDamage;
    
    hp -= comulativeDamage;
    
    if (hp > 0L) {
      long atacks = (hp + A - 1L) / A;
      ans += atacks;
      comulativeDamage += A*atacks;
      q.push({x+2L*D,A*atacks});
    }
    
  }

  cout << ans << endl;
  
  return 0;
}