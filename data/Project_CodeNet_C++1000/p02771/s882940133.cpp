#include <bits/stdc++.h>
 
typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout<<i<<endl;
#define AS(i) cout<<i<<" ";
 
const int INF = 1001001001;
 
using namespace std;
 
int main() {

    int a, b, c;
    cin >> a >> b >> c;

    string ans = "Yes";
    if ( (a==b && b==c && a==c) || (a!=b && b!=c && a!=c) ) {
        ans = "No";
    }

    cout << ans << endl;
}

