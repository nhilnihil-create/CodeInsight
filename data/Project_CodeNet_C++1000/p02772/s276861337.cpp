#include <bits/stdc++.h>
 
typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout<<i<<endl;
#define AS(i) cout<<i<<" ";
 
const int INF = 1001001001;
 
using namespace std;
 
int main() {

    int n;
    cin >> n;

    int a;
    rep(i, n) {
        cin >> a;

        if (a % 2 == 0) {

            if (a % 3 != 0 && a % 5 != 0 ) {
                AA("DENIED");
                return 0;
            }
        }
    }

    AA("APPROVED");
}

