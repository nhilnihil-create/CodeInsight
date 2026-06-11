#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  bool flg = false;

  for(int i = 1; i <= 9; i++){
    if(N%i == 0){
      int j = N / i;
      if(j <= 9 && j >= 1){
        flg = true;
        break;
      }
    }
  }

  if(flg){
    cout << "Yes" << endl;
  } else { 
    cout << "No" << endl;
  }
}
