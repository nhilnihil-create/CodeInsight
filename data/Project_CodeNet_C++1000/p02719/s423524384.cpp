#include<bits/stdc++.h>
using namespace std;
int64_t fabs(int64_t x)
{
    if(x<0)return -x;
    return x;
}
int main()
{
    int64_t N,K;
    cin>>N>>K;
    N -= K*(N/K);
    int64_t a1=N;
    int64_t a2=fabs(N-K);
    while(a1>a2)
    {
        a1=a2;
        a2=fabs(a1-K);
    }
    cout<<a1;
}