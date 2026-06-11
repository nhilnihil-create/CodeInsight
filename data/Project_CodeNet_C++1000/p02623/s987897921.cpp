#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

long long M,N,K,ans;
long long A[200002],B[200002];

int main()
{
    cin >> N>>M>>K;
    long long i,j;
    rep0(i,N) {cin>>j; A[i+1]=j+A[i];}
    rep0(i,M) {cin>>j; B[i+1]=j+B[i];}
    
    j=M;
    rep0(i,N+1) {
        if(A[i]>K) break;
        while(A[i]+B[j]>K && j>=0) --j;
        ans=max(ans,i+j);
    }

    cout << ans << endl;
    return 0;
}