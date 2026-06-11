#include <bits/stdc++.h>
 
typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout<<i<<endl;
#define AS(i) cout<<i<<" ";
 
const int INF = 1001001001;
 
using namespace std;
 
int main() {

    int n, r;
    cin >> n >> r;

    int ans = r;

    if (n < 10) {
        ans = r + 100 * ( 10 - n);
    }

    cout << ans << endl;
}