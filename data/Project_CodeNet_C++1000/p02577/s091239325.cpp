#include<bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin >> n;
  long long sum = 0;
  int length = n.size();
  for(int i = 0; i < length; i++){
    sum += n[i] - '0';
  }
  if(sum % 9 == 0){
    cout << "Yes" << endl;
  } else{
    cout << "No" << endl;
  }
  return 0;
}