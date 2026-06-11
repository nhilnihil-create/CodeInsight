#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(void){
  cin >> n >> s;
  int res = 0;
  for(int i = 0; i < 1000; i++){
    stringstream ss;
    ss << setw(3) << setfill('0') << i;
    string m = ss.str();
    int p, q, r;
    p = 0;
    while(p < n && s[p] != m[0]) p++;
    q = p+1;
    while(q < n && s[q] != m[1]) q++;
    r = q+1;
    while(r < n && s[r] != m[2]) r++;
    if(r < n) res++;
  }
  cout << res << endl;
  return 0;
}
