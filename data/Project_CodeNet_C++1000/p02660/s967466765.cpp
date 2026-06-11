#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
using namespace std;
using i64 = int64_t;
using pii = pair<i64, int>;
using vpii = vector<pii>;

vpii PF(i64 n){
    vpii pf;
    for(i64 i=2; i*i<=n; i++){
        if(n%i != 0) continue;
        int ex = 0;
        while(n%i == 0){n /= i; ex++;}
        pf.push_back(pii(i, ex));
    }
    if(n != 1) pf.push_back(pii(n, 1));
    return pf;
}

int main(void){
    i64 n;
    cin >> n;
    vpii pf = PF(n);
    int cnt = 0;
    for(const pii &x : pf){
        int ex = x.second; 
        for(int i=1; ex>=i; i++){
            ex -= i;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}