#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin >> n;
  
  vector<long long int> vec(n);
  
  for(int i = 0;i < n;i ++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  
  cout << vec.at(n / 2) - vec.at((n / 2) - 1) << endl;
}