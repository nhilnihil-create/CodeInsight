#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i,n){
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto ele : mp){
        if (ele.second > 1){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
