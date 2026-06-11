#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int c = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == c + 1) c++;
    }
    if(c == 0) cout << -1;
    else cout << n - c;

    return 0;
}
