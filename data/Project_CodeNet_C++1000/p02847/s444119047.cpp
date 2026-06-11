#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;	cin >> s;
  vector<string>	day={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  for(int i=0;i<7;i++){
    if(day[i]==s)	cout << 7-i;
  }
}