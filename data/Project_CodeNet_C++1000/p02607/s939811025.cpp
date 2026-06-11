#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,s,c=0,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s;
        if(i%2!=0 && s%2!=0)
            c++;
    }
    cout<<c<<endl;
}
