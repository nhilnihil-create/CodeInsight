#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[4]{};
    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    for(int i = 1; i <= 3; i++) if(a[i] == 0) cout << i;

    return 0;
}
