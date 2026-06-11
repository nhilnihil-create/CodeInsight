#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, x, i;
    cin >> k >> x;
    for(i=(x-k+1); i<=(x+k-1); i++){
        cout << i << ' ';
    }

    return 0;
}
