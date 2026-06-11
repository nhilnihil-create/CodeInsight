#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  string s, ss;
  cin >> s >> ss;
  int a = s.size();
  rep(i, 0, a){
    if(s[i] != ss[i]){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}