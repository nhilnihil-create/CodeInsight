#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,i,e,f,g,n,m,k,l,A[500005],B[500005];
int main() {
    cin>>n;
    for(long long i=1;i<=n;i++) {
        cin>>a>>b;
        A[i]=a+b;
        B[i]=a-b;
    }
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    cout<<max(A[n]-A[1],B[n]-B[1]);
}