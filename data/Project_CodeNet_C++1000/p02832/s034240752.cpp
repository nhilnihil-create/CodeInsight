#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int n;
    cin >> n;
    int t = 1;
    int k = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(a == t){
            k++;
            t++;
        }
    }
    if(k != 0) cout << n-k << endl;
    else cout << -1 << endl;
}