#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  string s;
  cin >> s;
  if((s.at(2) == s.at(3)) && (s.at(4) == s.at(5))) cout << "Yes" << endl;
  else cout << "No" << endl;
}
