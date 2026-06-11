#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int H, N;
    cin >> H >> N;

    int sum=0;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;

        sum += A;
    }

    if(H <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}
