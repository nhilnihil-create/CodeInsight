#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
    int N;
    cin >> N;

    vector<long double> A(N);
    rep(i,N) cin >> A.at(i);

    long double R = 0;

    rep(i,N){
        R += 1/A.at(i);
    }

    cout << fixed << setprecision(15) << 1/R << endl;
    
    

}