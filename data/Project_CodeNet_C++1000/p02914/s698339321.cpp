#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

int main(void) {
    int N;
    cin>>N;
    vector<Int> A(N);
    for(int i = 0;i < N;i++) {
        cin>>A[i];
    }
    Int s = 0;
    for(int i = 0;i < N;i++) {
        s ^= A[i];
    }
    Int ans = s;
    for(int i = 0;i < N;i++) {
        A[i] &= ~s;
    }

    int r = 0;
    vector<int> top(N);
    for(int i = 60;i >= 0;i--) {
        int j = r;
        for(;j < N;j++) {
            if(A[j]>>i&1) {
                swap(A[r],A[j]);
                break;
            }
        }
        if(j == N)
            continue;
        top[r] = i;
        for(int k = 0;k < N;k++) {
            if(r == k)
                continue;
            if(A[k]>>i&1)
                A[k] ^= A[r];
        }
        r++;
    }
    Int x = 0;
    for(int i = 60;i >= 0;i--) {
        Int nx = x |(1LL<<i);
        {
            Int b = nx;
            for(int j = 0;j < r;j++) {
                if(b>>top[j]&1)
                    b ^= A[j];
            }
            if((b&nx) == 0)
                x = nx;
        }
    }
    ans += x*2;
    cout<<ans<<endl;

    return 0;
}
