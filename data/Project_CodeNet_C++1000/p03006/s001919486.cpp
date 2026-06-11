#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    int data[n][2]; rep(i,n) rep(j,2) cin >> data[i][j];
    map<pair<int,int>,int> ans1;
    vector<pair<int,int>> ans2;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            pair<int,int> pp = {data[i][0]-data[j][0], data[i][1]-data[j][1]};
            ans1[pp]++; ans2.push_back(pp);
        }
    }
    int answer = 0;
    for(auto pp : ans2){
        answer = max(answer, ans1[pp]);
    }
    cout << n - answer << endl;
}