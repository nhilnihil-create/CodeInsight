#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  cout << (n/500)*1000 + ((n%500)/5)*5 << endl; 
  return 0;
}
