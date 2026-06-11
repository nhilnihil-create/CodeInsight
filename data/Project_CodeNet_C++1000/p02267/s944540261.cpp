#include <iostream>
using namespace std;

int *s;
int *t;
int n, q;

void solve(){
  int count = 0;
  for(int i = 0; i < q; i++){
    for(int j = 0; j < n; j++){
      if(s[j] == t[i]){
        count++;
        break;
      }
    }
  }
  cout << count << endl;
  return ;
}


int main(){
  cin >> n;
  s = new int[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  cin >> q;
  t = new int[q];
  for(int i = 0; i < n; i++) cin >> t[i];
  solve();
  return 0;
}