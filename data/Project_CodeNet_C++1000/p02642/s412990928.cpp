#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int ans, N, A[200001];
int a[1000001];
bool f[1000001],d[1000001];


int main()
{
    int i, j,m=0;
    cin >> N;

    rep(1,i, N+1){
        cin >>A[i];
        a[A[i]]++;
        m=max(m,A[i]);
    }
    rep(1,i,N+1){
        if (f[A[i]]||d[A[i]]) continue;
        for(j=A[i]*2;j<m+1;j+=A[i])
            f[j]=true;
        if(a[A[i]]>1) f[A[i]]=true;
        d[A[i]]=true;
    }
    
    rep(1,i, N+1)
    {
        if(!f[A[i]])ans++;
    }

    cout <<ans<<endl;
    return 0;
}