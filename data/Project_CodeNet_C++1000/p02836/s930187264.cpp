#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    string s;
    cin >> s;
    int n=s.size(), ans=0;
    for(int i=0; i<n/2; ++i){
        if(s[i]==s[n-i-1]) continue;
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}