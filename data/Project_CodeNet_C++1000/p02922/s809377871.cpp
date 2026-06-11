#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int A,B;
    cin >> A >> B;
    int cnt = 0;

    if (B == 1){
        cout << 0 << endl;
    }

    if (B!= 1){
        if (B-A >= 0){
            cnt++;
            B -= A;
        }

        while (B > 0){
            B -= (A - 1);
            cnt++;
        }
        cout << cnt << endl;
    }
}
