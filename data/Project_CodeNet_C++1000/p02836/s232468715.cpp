#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < (n+1)/2;i++){
        if(s.at(i) != s.at(n-1-i))ans++;
    }
    cout << ans << endl;

}