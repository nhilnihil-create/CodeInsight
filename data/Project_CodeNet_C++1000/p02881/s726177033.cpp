#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m=0,s,l=0,c=0,i,k,b;
    cin>>n;
    m=n-1;
    for(i=1;i<=sqrt(n);i++){
        if(!(n % i)){
            k=i;
            s=n/k;
            m=min(m,(k-1)+(s-1));
            l=1;
        }
    }
    if(l)
        cout<<m;
    else
        cout<<n-1;
}
