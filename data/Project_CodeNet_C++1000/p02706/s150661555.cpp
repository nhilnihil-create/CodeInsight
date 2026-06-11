#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int total = 0;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        total += a;
    }

    cout << max(-1, n - total) << endl;
    return 0;
}