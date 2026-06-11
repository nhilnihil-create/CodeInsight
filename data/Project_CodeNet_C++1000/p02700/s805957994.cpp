#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int main(void) {
    int A, B, C, D;

    cin >> A >> B >> C >> D;

    bool tturn = true;
    while(A > 0 && C > 0){
        if(tturn){
            C -= B;
        } else {
            A -= D;
        }
        tturn = !tturn;
    }

    if(A > 0){
        cout << "Yes" <<endl;
    } else {
        cout << "No"<< endl;
    }

    return 0;
}
