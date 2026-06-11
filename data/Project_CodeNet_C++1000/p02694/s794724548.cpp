#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x;
  cin>>x;
  long long yokin=100;
  long long year = 0;
  while(yokin < x){
    yokin += yokin/100;
    year++;
  }
  cout << year;
}