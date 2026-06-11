#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define arr(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
    FAST;
    ll N,T,i,j,a,b,k=0;
    int A[100]={},B[100]={};
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        B[i]=A[i];
    }
    sort(A,A+N);
    for(i=0;i<N;i++)
    {
        if(A[i]==B[i]) k++;
    }
    if(k==N-2 || k==N) cout<<"YES";
    else cout<<"NO";
    return 0;
}
