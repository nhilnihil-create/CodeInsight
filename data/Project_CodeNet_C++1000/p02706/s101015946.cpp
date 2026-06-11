#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

int main(){
    int n, m, tmp, ans;
    cin >> n >> m;
    int sum = 0;
    rep(i, m){
        cin >> tmp;
        sum += tmp;
    }
    ans = n - sum;

    cout << ((ans >= 0) ? ans : -1) << endl;

    return 0;
}