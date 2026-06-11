#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main () {
    int N ;
    cin >> N ;
    int ans ;
    ans = N/2 ;
    if (N%2 == 1){
        ans++ ;
    }
    cout << ans << endl;
}
