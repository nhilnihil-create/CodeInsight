#include <iostream>
#include <map>
#include <string>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> mp;
  rep(i, N) {
    string s;
    cin >> s;
    mp[s]++;
  }
  
  cout << "AC x " << mp["AC"] << endl;
  cout << "WA x " << mp["WA"] << endl;
  cout << "TLE x " << mp["TLE"] << endl;
  cout << "RE x " << mp["RE"];
}

