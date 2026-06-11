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
  int a;
  cin >> a;
  string s, t;
  cin >> s >> t;
  int n = 2 * a;
  rep(i, 0, n){
    if(i % 2 == 0){
      cout << s[i / 2];
    }
    else{
      cout << t[i / 2];
    }
  }
  cout << "\n";
}
