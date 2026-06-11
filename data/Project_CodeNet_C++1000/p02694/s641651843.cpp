#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t x;
  cin >> x;
  
  int64_t sum = 100;
  int year = 0;
  while(sum < x){
    sum += sum / 100;
    year++;
  }
  
  cout << year << endl;
}