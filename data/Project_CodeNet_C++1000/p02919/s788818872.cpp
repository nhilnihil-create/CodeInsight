#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++) 

int main(){
    int N; cin >> N;
    int index[N+1];
    repn(i, N){
        int p; cin >> p;
        index[p] = i;
    }
    multiset<int> S{0, 0, N+1, N+1};
    S.insert(index[N]);
    long sum = 0;
    for (int a = N-1; a >= 1; a--){
        auto itr = S.lower_bound(index[a]);
        int R1 = *itr; int R2 = *++itr; --itr;
        int L1 = *--itr; int L2 = *--itr;
        long c = (L1-L2)*(R1-index[a]) + (index[a]-L1)*(R2-R1);
        sum += c * a;
        S.insert(index[a]);
    }
    cout << sum << endl;
}