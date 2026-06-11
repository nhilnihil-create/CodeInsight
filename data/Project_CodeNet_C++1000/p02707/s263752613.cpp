#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<int> v(N, 0);

  for(int i = 0; i < N-1; i++){
    int tmp; cin >> tmp;
    tmp--;
    v[tmp]++;
  }

  for(int i = 0; i < N; i++){
    cout << v[i] << endl;
  }
}
