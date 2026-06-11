#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
 
int main(){
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    REP(i,N) {
        cin >> A[i]; A[i] --;
        B[A[i]] ++;
    }
    vector<int> cnt(N+2,0);
    REP(i,N) {
        cnt[B[i]]++;
    }
    for(int i=N-1; i>=1; --i) {
        cnt[i] += cnt[i+1];
    }
    for(int i=2; i<=N; ++i) {
        cnt[i] += cnt[i-1];
    }
    for(int i=1; i<=N; ++i) {
        int ub = N+1;
        int lb = 0;
        int mid;
        while (ub-lb>1) {
            mid = (ub + lb) / 2;
            if((long long)cnt[mid] >= (long long)mid*i) lb = mid;
            else ub = mid;
        }
        cout << lb << endl;
    }
    return 0;
}
