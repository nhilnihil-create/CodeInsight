#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define int long long
#define elif else if
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
signed main(){
  
  string s;
  cin >> s;
  int n = s.size();
  //cout << n / 2 << "\n";
  rep(i, 0, n / 2){
    //cout << s[i] << " " << s[n - i - 1] << "\n";
    if(s[i] != s[n - i - 1]){
      cout << "No\n";
      return 0;
    }
  }
  
  int nn = (n - 1) / 2;
  //cout << nn << "\n";
  rep(i, 0, nn / 2){
    //cout << s[i] << " " << s[nn - 1 - i] << "\n";
    if(s[i] != s[nn - 1 - i]){
      cout << "No\n";
      return 0;
    }
  }
  nn = (n + 3) / 2;
  int m = n - nn;
  nn--;
  rep(i, 0, m / 2){
   // cout << s[nn + i]  << " " << s[n - 1 - i] << "\n";
    if(s[nn + i] != s[n - 1 - i]){
      cout << "No\n";
      return 0;
    }
  }
  
  cout << "Yes\n";
  return 0;
}