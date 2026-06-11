#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int>B(N,0);
    int count = 0;
    int i = 0;
    int j = 0;
    long long x,y,z;
    int now;
    while (count == 0){
        now = A.at(i);
        if (B.at(now-1) == 0){
            B.at(now-1) = j + 1;
            i = now - 1;
            j++;
        }
        else {
            x = B.at(now-1) - 1;
            y = j + 1 - B.at(now-1);
            count = 1;
        }      
    }

    if (x == 0){
        if (K <= j){
            z = K;
        }
        else {
            if (K % y == 0){
                z = y;
            }
            else {
                z = K % y;
            }
        }
    }
    else {
        if (K <= j){
            z = K;
        }
        else {
            if ((K-x) % y == 0){
                z = x + y;
            }
            else {
                z = (K-x) % y + x;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        if (B.at(k) == z){     
            cout << k + 1 << endl;
            return 0;
        }
    }
}