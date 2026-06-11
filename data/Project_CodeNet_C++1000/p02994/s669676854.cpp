#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,L;
    int val,sum,minval;
    cin >> N >> L;
    
    // L+(1karaN)-1 の最小
    minval = 1000;
    sum = 0;
    for(int i=0;i<N;i++) {
        val = L + i;
        if(abs(minval) > abs(val)) {
            minval = val;
        }
        sum += val;
    }

    cout << sum - minval << endl;

    return 0;
}
