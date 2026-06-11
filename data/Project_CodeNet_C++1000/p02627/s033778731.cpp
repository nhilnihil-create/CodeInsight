#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>

#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  
  char a; cin >> a;
  
  if(isupper(a)){
    cout << "A" << endl;
  }else{
    cout << "a" << endl;
  }
  
  return 0;
  
}
