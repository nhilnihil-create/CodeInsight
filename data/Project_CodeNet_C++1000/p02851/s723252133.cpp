#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = (s[i] + a[i])%k;
    }
    map<int, int> mp;
    ll ans = 0;
    queue<int> q;
    rep(j, n+1){
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        if(q.size() == k){
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
}