#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
string s; cin >>s;
int n = s.size();

string t;
for(int i = 0; i< (n-1)/2; i++)t += s[i];
string u = t;
reverse(t.begin(), t.end());
bool ans = true;
for(int i = 0; i< (n-1)/2; i++){
   if(u[i]==t[i])continue;
   else ans = false;
}

string v;
for(int i = (n+1)/2; i < n; i++)v += s[i];
string w = v;
reverse(v.begin(), v.end());
for(int i = 0; i < (n-1)/2 ; i++){
   if(w[i]==v[i])continue;
   else ans = false;
}

if(v != t) ans = false;

if(ans) cout << "Yes" << endl;
else cout << "No" << endl;
return 0;
}