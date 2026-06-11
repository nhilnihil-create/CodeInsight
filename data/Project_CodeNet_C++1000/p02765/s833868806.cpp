#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
int N, R;
cin >> N >> R;

    if(N >= 10) {
        cout << R;
    }else {
        cout << R + 100 * (10 - N);
    }

    
    return 0;
}