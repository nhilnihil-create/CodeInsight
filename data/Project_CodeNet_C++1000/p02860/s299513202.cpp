#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;	cin >> n;
  string s;	cin >> s;
  if(s.size()%2!=0){
    cout << "No";
    return 0;
  }
  string t=s.substr(0,n/2);
  if(t==s.substr(n/2,n/2))	cout << "Yes";
  else	cout << "No";
}