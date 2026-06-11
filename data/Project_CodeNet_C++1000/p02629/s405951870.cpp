#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  vector<int> a;
  int i=0;
  while(N>0){
    N -= 1;
    a.push_back(N%26);
    N/=26;
  }
  
  for(ll j=a.size()-1;j>=0;j--){
    cout << char('a'+a[j]);
  }
  cout << endl;
  return 0;
}
