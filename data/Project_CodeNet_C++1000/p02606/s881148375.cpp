#include <bits/stdc++.h>
using namespace std;

int main() {
    int L,R,d;
    cin >> L >> R >> d;

    int sum  = 0;
    for(int i = L; R >= i; i++){
        if(i % d == 0){
            sum++;
        }
    }
    cout << sum << endl;
}