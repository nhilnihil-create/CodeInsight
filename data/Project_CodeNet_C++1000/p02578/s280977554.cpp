#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 77;


int A[N];

int32_t main(){
    int n , mx = 0, ans = 0; cin >> n ;
    for(int i = 0 ; i < n ; ++i){
        cin >> A[i];
        mx = max(mx,A[i]);
        ans += (mx - A[i]);
    }
    cout << ans << endl;
    return 0;
}