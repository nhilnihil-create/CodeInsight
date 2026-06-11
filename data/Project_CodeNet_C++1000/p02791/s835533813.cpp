#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    int N; cin >> N;
    int P[N+10] = {0};
    int count = 1;
    for(int i=0; i<N; i++) {
        cin >> P[i];
    }
    int min = P[0];
    for(int i=1; i<N; i++) {
        if(P[i]<min) {
            min = P[i];
            count++;
        }
    }
    cout << count << endl;
}