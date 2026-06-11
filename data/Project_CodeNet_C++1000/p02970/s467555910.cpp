#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    int each = 2*d + 1;
    if(n%each == 0)
        cout << n/each << '\n';
    else
        cout << n/each + 1 << '\n';

    return 0;
}
