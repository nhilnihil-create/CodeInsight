#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  string sun = "Sunny",clo = "Cloudy",rai = "Rainy";
  if(s == sun) cout << clo << endl;
  else if (s == clo) cout << rai << endl;
  else cout << sun << endl;

}
