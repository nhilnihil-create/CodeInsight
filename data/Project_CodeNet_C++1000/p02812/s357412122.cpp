#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n - 2;i++){
        if(s.at(i) == 'A' && s.at(i+1) == 'B' && s.at(i+2) == 'C') ans++;
    }
    cout << ans << endl;
}