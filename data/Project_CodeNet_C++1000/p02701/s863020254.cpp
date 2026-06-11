#include<iostream>
#include<string>
#include<set>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n;
  cin >> n;
  set<string> s;
  rep(i, 0, n){
    string a;
    cin >> a;
    s.insert(a);
  }
  
  cout << s.size();
}