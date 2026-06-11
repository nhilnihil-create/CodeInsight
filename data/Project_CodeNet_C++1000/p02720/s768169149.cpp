#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int k;
    cin >> k;
    queue<ll>q;
    for(int i = 1;i<=9;i++) q.push(i);
    ll ans = 0;
    rep(i,k) {
        ll cur = q.front();q.pop();
        if(i==k-1) {
            cout << cur << endl;
            return 0;
        }
        int add = cur%10;
        if(add>=1) {
            ll next = cur*10+add-1;
            q.push(next);
        } 
        q.push(cur*10+add);
        if(add<=8) {
            ll next = cur*10+add+1;
            q.push(next);
        }
        
    }
}