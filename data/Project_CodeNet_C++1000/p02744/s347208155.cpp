#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    queue<pair<lli, string>> q;
    q.push({1, "a"});
    while(!q.empty()){
        string t = q.front().second;
        lli k = q.front().first;
        q.pop();
        if(t.size() == n){
            cout << t << endl;
            continue;
        }
        rep(i, k){
            q.push({k, t+char('a'+i)});
        }
        q.push({k+1, t+char('a'+k)});
    }
    return 0;
}
