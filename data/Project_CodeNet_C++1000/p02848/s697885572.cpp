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
  int a = s.size();
  rep(i, 0, a){
    rep(j, 1, n + 1){
      s[i]++;
      if(s[i] == '['){
        s[i] = 'A';
      }
    }
    cout << s[i];
  }
  cout << "\n";
}