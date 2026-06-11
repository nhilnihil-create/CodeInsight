#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){ 
int n; cin >> n;
map<string, int> mp;
vector<string>  a(n);
int mx = 0;
for(int i = 0; i < n; i++){
string s; cin >> s;
a[i] = s;
mp[s]++;
mx = max(mx, mp[s]);
if(mp[s]>=2)a[i] ="-1";
}
vector<string> b;
for(int i = 0; i < n; i++){
if(mp[a[i]]==mx) b.push_back(a[i]);
}
sort(b.begin(), b.end());
for(int i = 0; i < b.size(); i++) cout << b[i] << endl;
return 0;
}
