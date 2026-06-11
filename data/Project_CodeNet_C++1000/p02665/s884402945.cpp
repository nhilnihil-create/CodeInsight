#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    long long A[N + 1];
    for(int i = 0; i < N + 1;i++){
        cin >> A[i];
        //cout << A[i] <<endl;
    }
    
    long long lim[N+1];
    lim[0] = 1;
    
    for(int i = 1; i < N + 1;i++){
        long long m = (lim[i-1] - A[i-1])*2LL;
        if(m<0){cout << -1 <<endl;return 0;}
        lim[i] = min(m,1000000000000000LL);
        //cout <<"lim"<< lim[i] <<endl;
    }
    
    if(lim[N]<A[N]){cout << -1 <<endl;return 0;}
    
    
    long long res = A[N];
    long long calc = A[N];
    for(int i = N-1; i >= 0;i--){
        calc += A[i];
        calc = min(lim[i],calc);
        //cout << calc <<endl;
        res += calc;
        //cout << lim[i] <<endl;
    }
    cout << res <<endl;
}
