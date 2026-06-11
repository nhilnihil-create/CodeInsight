#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,X,L;
    int sum,cnt;
    cin >> N >> X;

    sum = 0;
    cnt = 1;
    for(int i=0;i<N;i++) {
        cin >> L; 
        sum += L;
        if(sum <=X) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}