#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll);
ll mod_fact(ll, ll);
ll mod_inv(ll, ll);
//
int main(){
    int n, m;
    cin >> n >> m;
    if(m % 2){
        for(int l = 1, r = m; l < r; l++, r--){
            cout << l << " " << r << "\n";
        }for(int l = m + 1, r = 2 * m + 1; l < r; l++, r--){
            cout << l << " " << r << "\n";
        }
    }else{
        for(int l = 1, r = m + 1; l < r; l++, r--){
            cout << l << " " << r << "\n";
        }for(int l = m + 2, r = 2 * m + 1; l < r; l++, r--){
            cout << l << " " << r << "\n";
        }
    }
}