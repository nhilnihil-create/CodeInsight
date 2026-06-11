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
  string s, t;
  int sm = 0;
  cin >> s >> t;
  rep(i, 0, 3){
    if(s[i] == t[i]){
      sm++;
    }
  }
  
  cout << sm << "\n";
}
      
    