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

ll n;
ll a[10000001];


void fuct(){
    for (ll i = 2; i <= n; i++){
        if(a[i] == 1){
            for (ll j = i; j <= n; j += i){
                ll m = j;
                ll num = 0;
                while (m % i == 0){
                    m /= i;
                    num++;
                }
                a[j] *= (num + 1);
            }
        }
    }
}

int main(){
    cin >> n;
    fill(a, a + n + 1, 1);
    fuct();
    // rep(i, n+1){
    //     cout << i << ": " << a[i] << endl;
    // }
    ll ans = 0;
    for (ll i = 1; i <= n; i++){
        ans += a[i] * i;
    }
    cout << ans << endl;
}