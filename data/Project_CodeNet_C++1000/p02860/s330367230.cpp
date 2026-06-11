#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  if(n % 2 == 1){
    cout << "No\n";
    return 0;
  }
  n = n / 2;
  string ss = s.substr(n);
  rep(i, 0, n){
    if(s[i] != ss[i]){
      cout << "No\n";
      return 0;
    }
  }
  
  cout << "Yes\n";
}