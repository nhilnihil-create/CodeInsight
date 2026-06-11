#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a;
  cin >> a;
  string s;
  cin >> s;
  if(a < 3200){
    cout << "red\n";
  }
  else{
    cout << s << "\n";
  }
}