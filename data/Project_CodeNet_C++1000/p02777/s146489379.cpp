#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
using namespace std;

int main(){
  string s,t,u;
  int a,b;
  cin >> s >> t >> a >> b >> u;
  s==u ? cout << a-1 << " " << b << endl : cout << a << " " << b-1 << endl;
}