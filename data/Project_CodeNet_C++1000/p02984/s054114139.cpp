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
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll sm = 0;
    rep(i, n){
        if(i % 2 == 0) sm += a[i];
        else sm -= a[i];
    }
    ll x[n];
    x[0] = sm / 2;
    rep(i, n - 1){
        x[i+1] = a[i] - x[i];
    }
    rep(i, n){
        cout << x[i] * 2 << " ";
    }cout << endl;
}