#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h, n;
    cin >> h >> n;
    while(n--){
        int x;
        cin >> x;
        h -= x;
    }
    if(h <= 0) cout << "Yes";
    else cout << "No";

    return 0;
}
