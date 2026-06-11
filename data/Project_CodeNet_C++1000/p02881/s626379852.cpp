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
    ll ans = 100100100100100100;
    for (ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans = min(ans, (i - 1) + (n / i) - 1);
        }
    }
    cout << ans << endl;

}