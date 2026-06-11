#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
 int n;
 cin >> n;
 map<string,int> mp;
 rep(i,n){
   string s;
   cin >> s;
   mp[s]++;
 }
 int m = -1;
 for(auto itr = mp.begin(); itr != mp.end(); itr++){
   m = max(m,itr->second);
 }
 vector<string> a;
 for(auto itr = mp.begin(); itr != mp.end(); itr++){
   if(itr->second == m) a.push_back(itr->first);
 }
 sort(a.begin(),a.end());
 rep(i,a.size()) cout << a.at(i) << endl;
}