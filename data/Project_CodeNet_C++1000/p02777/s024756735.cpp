#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2;
  cin >> s1 >> s2 ;
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  if(s==s1)a--;
  if(s==s2)b--;
  cout << a << " " << b << endl;
}
