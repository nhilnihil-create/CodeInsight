#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int k, q;
    cin >> k >> q;
    vector<i64> d;
    for(int i=0;i<k;++i){
        i64 tmp;
        cin >> tmp;
        d.push_back(tmp);
    }
    for(int t=0;t<q;++t){
        i64 n, x, m;
        cin >> n >> x >> m;
        auto v = d;
        for(auto &e: v)e %= m;
        x %= m;
        i64 sum = x, equal = 0;
        for(i64 i=0;i<k;++i){
            if(v[i] == 0){
                equal += (n-1) / k;
                if(i < (n-1)%k)equal++;
            }
            sum += (n-1) / k * v[i];
            if(i < (n-1)%k)sum += v[i];
        }
        i64 large = sum / m - x / m;
        //cerr << sum << " " << large << " " << equal << endl;
        cout << (n-1) - large - equal << endl;
    }

    return 0;
}