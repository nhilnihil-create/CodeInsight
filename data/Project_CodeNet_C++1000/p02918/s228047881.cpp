#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n,k;cin>>n>>k;
    string s;cin >>s;

vector<int> v;
v.push_back(1);
int le = s.length();
for(int i=1;i<le;i++){
    if(s[i]!=s[i-1]) v.push_back(1);
    else v[v.size()-1]+=1;
}
if(2*k<v.size()) cout << le-v.size()+2*k;
else cout << le-1;
}