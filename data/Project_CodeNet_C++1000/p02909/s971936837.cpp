#include<bits/stdc++.h>
using namespace std;

int main(void){
  string S;
  cin >> S;
  if(S == "Sunny")
    cout << "Cloudy" << "\n";
  else if(S == "Cloudy")
    cout << "Rainy" << "\n";
  else if(S == "Rainy")
    cout << "Sunny" << "\n";
  return 0;
}
