// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k,x; cin >> k >> x;
    for(int i = x-k+1; i < x+k; ++i) cout << i << "\n";
}