#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3])cout << "Bad" << endl;
  else cout << "Good" << endl;

}