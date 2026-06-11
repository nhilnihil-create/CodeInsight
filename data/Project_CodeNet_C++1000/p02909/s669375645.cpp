#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin >> S;
  
  if (S=="Sunny"){
    T="Cloudy";
  }
  else if(S=="Cloudy"){
    T="Rainy";
  }
  else if(S=="Rainy"){
    T="Sunny";
  }
  
  cout << T<< endl;

}
