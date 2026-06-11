#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  map<ll,int> m;
  int N; cin >> N;

  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    if(m.count(tmp) != 0){
      cout << "NO" << endl;
      return 0;
    }
    m[tmp]++;
  }
  cout << "YES" << endl;
}


