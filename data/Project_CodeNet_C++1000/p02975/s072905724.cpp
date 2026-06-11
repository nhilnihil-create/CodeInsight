#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 200005;
const int mod = 998244353;
int v[10005];
ll dp[10005][1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int>mp;
    f(n) {
        int x;
        cin >> x;
        mp[x]++;
    }
    if (mp.size() == 1 && mp.begin()->F == 0) {
        cout << "Yes\n";
        exit(0);
    }
    if (n % 3 != 0) {
        cout << "No\n";
        exit(0);
    }
    vector<int>v;
    for (auto &i : mp) {
        while(i.S >= n /3) {
            i.S -= n /3;
            v.pb(i.F);
        }
    }
    if (v.size() == 3 && (v[0] ^ v[1]) == v[2]) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}