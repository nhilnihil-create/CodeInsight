#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
vector<long long> divisor(long long n){//nの約数列挙
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    vector<long long> d = divisor(sum);
    sort(d.begin(), d.end());
    int size = d.size();
    for(int i = size - 1; i >= 0; i--){
        long long cnt = 0;
        vector<P> low(N);
        for(int j = 0; j < N; j++){
            long long temp = A[j] / d[i] * d[i];
            low[j] = P(A[j] - temp, temp + d[i] - A[j]);
        }
        sort(low.begin(), low.end());
        vector<P> sum(N + 1);
        sum[0] = P(0, 0);
        for(int j = 1; j < N + 1; j++){
            long long l = sum[j - 1].first + low[j - 1].first;
            long long r = sum[j - 1].second + low[j - 1].second;
            sum[j] = P(l, r);
        }
        for(int j = 0; j < N + 1; j++){
            if(sum[j].first == sum[N].second - sum[j].second && sum[j].first <= K){
                cout << d[i] << endl;
                return 0;
            }
        }
    }
}