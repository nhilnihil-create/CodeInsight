#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  
  set<long long> div;
  if(a > b) swap(a, b);
  for(long long i = 2; i * i <= a; i++){
    if(a % i) continue;
    div.insert(i);
    while(a%i == 0) a /= i;
  }
  div.insert(1);
  div.insert(a);
  long long ans = 0;
  for(auto now : div){
    if(b % now) continue;
    ans++;
  }
      
  cout << ans << endl;
}