#include <bits/stdc++.h>
using namespace std;

int main()
{
    long N;
    cin>>N;
    long int k;
    k=(N*100)/108;
    if((k*108/100)==N)
    cout<<k;
    else if((k-1)*108/100==N)
        cout<<k-1;
    else if((k+1)*108/100==N)
        cout<<k+1;
    else
        cout<<":(";
    return 0;
}

