#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    int N, K;
    int A[200010];
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    int sum[200010];
    sum[0]=0;
    for(int i=1; i<=N; i++)
    {
        sum[i]=(sum[i-1]+A[i])%K;
        sum[i]=(sum[i]+K-1)%K;
    }
    map<int, int> m;
    long long ans=0;
    for(int i=0; i<=N; i++)
    {
        if(i>=K) m[sum[i-K]]--;
        ans+=m[sum[i]];
        m[sum[i]]++;
    }
    /*for(int i=0; i<=N; i++)
    {
        cout << sum[i] << ' ' << m[sum[i]] << endl;
    }*/
    cout << ans << endl;
    return 0;
}