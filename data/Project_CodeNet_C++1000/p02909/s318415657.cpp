#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
 vector<string> a={"Sunny","Cloudy","Rainy","Sunny"};
  
  for(int i=0; i<3; i++){
  if(s==a[i]){
    cout << a[i+1] << endl;
  }
  }
  
  
  
}
