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
    ll n;
    cin >> n;
    if(n % 2 == 1 || n < 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll five = 5;
    while(five <= n){
        ans += (n/five) / 2;
        five *= 5;
    }
    cout << ans << endl;

}