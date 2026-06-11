#include <iostream>
#include <vector>
using namespace std;
struct BIT{
    vector<long long> num;
    int N;
    BIT(int n){
        N = n;
        num.resize(N + 1, 0);
    }
    long long sum(int t){
        long long res = 0;
        while(t > 0){
            res += num[t];
            t -= t & -t;
        }
        return res;
    }
    void add(int ind, long long t){
        while(ind <= N){
            num[ind] += t;
            ind += ind & -ind;
        }
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    BIT bit(N);
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        bit.add(i + 1, a);
    }
    for(int i = 0; i < Q; i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 0) bit.add(l + 1, r);
        else cout << bit.sum(r) - bit.sum(l) << endl;
    }
}