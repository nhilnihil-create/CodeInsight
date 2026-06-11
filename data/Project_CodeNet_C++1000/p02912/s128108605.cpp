#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    long long n,m;
    cin >> n >> m;
    
    priority_queue <long long> a;
    rep(i,n){
        long long A;
        cin >> A;
        a.push(A);
    }

    int cnt = 0;
    while(cnt < m){
        long long tmp = a.top()/2;
        a.pop();
        a.push(tmp);
        cnt ++;
    }

    long long ans = 0;
    rep(i,n){
        ans += a.top();
        a.pop();
    }
    cout << ans << endl;
}