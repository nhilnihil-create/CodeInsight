#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  int m = s.size();
  rep(i, m){
    int num = s[i] - 'A';
    num = (num + n) % 26;
    char c = 'A' + num;
    cout << c;
  }
  cout << endl;
  
  return 0;
}