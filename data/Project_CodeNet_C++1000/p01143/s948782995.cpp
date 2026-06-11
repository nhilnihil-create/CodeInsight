#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N, M, P;
  while(cin >> N >> M >> P, N || M || P){
    float money_sum = 0;
    vector<int> ticket_number;
    for(int i=0; i < N; i++){
      int tmp; cin >> tmp;
      ticket_number.push_back(tmp);
    }

    for(int i=0; i < N; i++){
      money_sum += ticket_number[i] * 100;
    }

    money_sum = money_sum * ((100 - (float)P) / 100);
    if(ticket_number[M-1] == 0){
      cout << 0 << endl; continue;
    }

    cout << int(money_sum / ticket_number[M-1]) << endl;

  }
  return 0;
}