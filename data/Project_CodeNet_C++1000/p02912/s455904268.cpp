#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int> a;
    rep(i, n) {
        int p;
        cin >> p;
        a.push(p);
    }
    rep(i, m){
        int p = a.top();
        a.pop();
        p /= 2;
        a.push(p);
    }
    ll ans = 0;
    rep(i, n){
        int p = a.top();
        a.pop();
        ans += p;
    }
    cout << ans << endl;


}