#include <bits/stdc++.h>
#include<math.h>
using ll = long long;
using namespace std;

int main(){
  string s;
 cin >> s;
 string t = s;
 int n = s.size();
 reverse(s.begin(), s.end());
 int cnt = 0;
 for(int i = 0; i< n; i++){
    if(s[i] != t[i]) cnt++;
 }
 int ans = cnt / 2;
 cout <<  ans  << endl;
return 0;
}