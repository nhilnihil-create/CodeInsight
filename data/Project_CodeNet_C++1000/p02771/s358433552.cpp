#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && a == c){
    cout << "No\n";
    return 0;
  }
  if(a != b && b != c && a != c){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}