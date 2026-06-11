#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,num=0;
    long long k;
    cin>>n>>m>>k;
    long long a[n+1],b[m+1];
    memset(a, 0, (n+1)*sizeof(a[0]));
    memset(b, 0, (m+1)*sizeof(b[0]));
    for(int i=0; i<n; i++)
    {
        cin>>a[i+1];
        a[i+1]+=a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>b[i+1];
        b[i+1]+=b[i];
    }
    for(int i=0, j=m; i<=n; ++i)// iterate on all possible values of a & b and we start with zero to consider the case of reading all from b
    {
        if(a[i]>k)// if a alone exceeds the sum then break
            break;
        while(a[i]+b[j]>k)// start with the largest value of b possible and decrease until you reach
            --j;
        num=std::max(i+j, num);//use max to store the max value of all possible combinations
    }
    cout << num;
    return 0;
}