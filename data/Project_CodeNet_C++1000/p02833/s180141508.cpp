#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;

int32_t main(){
    fast;
    int n; cin >> n ;
    if(n%2){
        cout << 0 << endl;
        return 0;
    }
    int a = 10 , b = 0;
    while(a <= n){
        b += n/a;
        a *= 5;
    }
    cout << b << endl;
    return 0;
}