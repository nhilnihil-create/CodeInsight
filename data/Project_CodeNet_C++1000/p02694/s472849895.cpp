#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  long long X, year, money;
  cin >> X;
  money = 100;
  year = 0;
  while(money < X){
    year++;
    money += (money / 100);
  }
  cout << year << endl;
}