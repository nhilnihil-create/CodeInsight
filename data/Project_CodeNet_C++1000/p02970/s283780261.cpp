#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;

    int ans = (n + d * 2) / (d * 2 + 1);

    cout << ans << endl;

    return 0;
    
}