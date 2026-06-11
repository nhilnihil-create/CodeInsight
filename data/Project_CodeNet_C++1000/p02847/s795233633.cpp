#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s; cin >>s;
  string t[7]={"SAT","FRI","THU","WED","TUE","MON","SUN"};
  for(int i=0;i<7;i++) if(s==t[i]) cout<<i+1<<endl;
}