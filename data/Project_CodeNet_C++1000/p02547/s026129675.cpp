#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, a[N], b[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    bool can = 0;
    for(int i = 2; i <= n - 1; i++){
        if(a[i] == b[i] && a[i - 1] == b[i - 1] && a[i + 1] == b[i + 1]){
            can = 1;
        }
    }
    cout << ((can) ? "Yes\n" : "No\n");
    return 0;
}