#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


vector<int64_t> divisor ( int64_t X ){
    vector<int64_t> ans_list;
    for ( int64_t i = 1; i <= sqrt(X); ++i){
        // 割り切れる場合
        if ( X % i == 0 ){
            if ( i != X/i ){
                ans_list.push_back(i);
                ans_list.push_back(X/i);
            } else {
                ans_list.push_back(i);
            }
        }
    }
    sort(ans_list.begin(),ans_list.end());
    return ans_list;
}

// N が K の倍数のときに、問題文の条件を満たすか?
bool condition (int64_t N, int64_t K){
    int64_t syo = N;
    while ( syo % K == 0 ){
        syo = syo / K;
    }
    if ( (syo - 1 ) % K == 0 ){
        return true;
    } else {
        return false;
    }
}


int main(){
    int64_t N;
    cin >> N;
    vector<int64_t> dvs, dvsN;
    dvs = divisor(N-1);
    int64_t res = dvs.size() - 1;
    
    dvsN = divisor(N);
    for ( int64_t i = 1; i < dvsN.size(); ++i){
        int64_t div = dvsN.at(i);
        bool flg = condition(N,div);
        if ( flg ) {
            //cout << div << endl;
            ++res;
        }
    }
    
    cout << res << endl;
    return 0;
}
