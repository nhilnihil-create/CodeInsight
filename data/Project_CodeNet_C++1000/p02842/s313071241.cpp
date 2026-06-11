#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // X * 1.08 = N
    double X = N / 1.08;
    int ans = (int)X;
    bool found = false;
    for(int i=ans-1; i<ans+2; i++) {
        if((int)(i * 1.08) == N) {
            cout << i << endl;
            found = true;
            return 0;
        }
    }
    if(!found){
        cout << ":(" << endl;
    }
}