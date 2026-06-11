#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

int main(){

  string s;
  cin >> s;

  if(s[0]==s[1] && s[1]!=s[2] && s[2]==s[3])cout << "Yes" << endl;
  else if(s[0]==s[2] && s[1]!=s[2] && s[3]==s[1])cout << "Yes" << endl;
  else if(s[0]==s[3] && s[1]==s[2] && s[3]!=s[1])cout << "Yes" << endl;
  else cout << "No" << endl;

}