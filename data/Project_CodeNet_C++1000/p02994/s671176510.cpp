#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,L;
    cin >> N >> L;
    long long goukei = 0;
    long long sa = 1e9;
    for(int i = 1; i <= N; i++) {
        long long X = i+L-1;
        goukei+=X;
        if(abs(sa) > abs(X)) sa = X;
    }
    cout << goukei-sa << endl;
    return 0;
}
