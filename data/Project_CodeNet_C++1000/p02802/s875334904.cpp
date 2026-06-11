#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N, M; cin >> N >> M;

  map<int,int> ac; // ACになったら1
  map<int,int> wa; // 間違えた回数

  int wa_num = 0;
  int ac_num = 0;

  for(int i = 0; i < M; i++){
    int num; string S;
    cin >> num >> S;
    if(S == "AC"){
      if(ac.count(num) == 0){
        wa_num += wa[num];
        ac[num] = 1;
        ac_num++;
      } else {

      }
    } else {
      if(ac.count(num) == 0){
        wa[num]++;
      } else {

      }
    }
  }

  cout << ac_num << " " << wa_num << endl;

}
