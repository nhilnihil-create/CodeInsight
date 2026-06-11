#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,s,c=0,i;
    cin>>n;
    for(i=1;i<10;i++){
        if(n%i==0)
        m=n/i;
        if(m>=1 && m<=9){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
