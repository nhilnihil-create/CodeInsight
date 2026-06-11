#include <bits/stdc++.h>
 
typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout<<i<<endl;
#define AS(i) cout<<i<<" ";
 
const int INF = 1001001001;
 
using namespace std;
 
int main() {

    int n, k;
    cin >> n >> k;

    int next = n;
    int cut = 0;
    while (next >= k) {
        next /= k;
        cut++;
    }
    cut++;

    cout << cut << endl;
}