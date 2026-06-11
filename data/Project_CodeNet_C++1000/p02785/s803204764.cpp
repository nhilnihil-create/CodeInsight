#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))



using namespace std;
typedef long long ll;

int main() {
    int n,k;
    cin >> n>> k;
    int hs[n];
    for (int i=0;i<n; i++){
        cin >> hs[i];
        // cout << hs[i] << endl;
    }
    if (k >= n) cout << 0 << endl;
    else {
        std::sort(hs, hs+SIZE_OF_ARRAY(hs));
        // cout << SIZE_OF_ARRAY(hs) << endl;
        ll s = accumulate(hs, hs + n-k, (ll) 0);
        cout << s << endl;
    }
}
