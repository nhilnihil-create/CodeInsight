#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,sum;
    cin>>n>>m>>sum;
    long long num=n/m+1;
    if (n%num==0) num-=1;

    for (int i=0;i<m;i++){
      cout<<sum<<" ";
    }
    if (sum!=1e9){
    for (int i=0;i<n-m;i++){
            cout<<(long long)1e9<<" ";
    }
}
    else{
        for (int i=0;i<n-m;i++){
            cout<<(long long)1e9/(n-m+3)<<" ";
    }
    }
    return 0;
}
