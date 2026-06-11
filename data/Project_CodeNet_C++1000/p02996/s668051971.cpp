#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N),B(N);
    vector<vector<int64_t>> BA(N,vector<int64_t>(2));
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i) >> B.at(i);
        BA.at(i).at(0) = B.at(i);
        BA.at(i).at(1) = A.at(i);
    }
    
    sort(BA.begin(),BA.end());
    
    int64_t t = 0;
    bool flg = true;
    for ( int64_t i = 0; i < N; ++i){
        t += BA.at(i).at(1);
        if ( t > BA.at(i).at(0) ) {
            flg = false;
        }
    }
    
    if ( flg ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    return 0;
}

