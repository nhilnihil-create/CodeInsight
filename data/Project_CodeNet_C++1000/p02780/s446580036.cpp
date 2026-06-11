#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,K; cin >> N >> K;
    int p[N+10] = {0};
    for(int i=0; i<N; i++) cin >> p[i];

    double index[1100] = {0};
    double sum_index[N+100] = {0};
    for(int i=1; i<=1000; i++) index[i] = double(1+i)/2;

    double sum = 0;
    for(int i=0; i<N; i++) {
        sum += index[p[i]];
        sum_index[i] = sum;
    }

    double max = sum_index[K-1];
    for(int i=1; i<=N-K; i++) {
        double ans = 0;
        ans = sum_index[i+K-1] - sum_index[i-1];
        if(max < ans) max = ans;
        }
    printf("%.8f\n",max);
}