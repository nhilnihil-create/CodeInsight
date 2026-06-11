#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  int cnt = 0;
  bool flg = false;
  for(int i = 0; i < N; i++){
    int tmp1,tmp2; cin >> tmp1 >> tmp2;
    if(tmp1 == tmp2){
      cnt++;
    } else { 
      cnt = 0;
    }

    if(cnt == 3){
      flg = true;
    }
  }

  if(flg){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
