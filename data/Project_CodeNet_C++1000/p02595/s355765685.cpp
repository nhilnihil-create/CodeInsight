#include<bits/stdc++.h>
using namespace std;
long long n,d;
int ans=0;
int main()
{
    cin>>n>>d;
    int a,b;
    double c;
    while(n>0)
    {
        cin>>a>>b;
        c=sqrt(pow(a,2)+pow(b,2));
        if(c<=d)
            ans++;
        n--;
    }
    cout<<ans<<endl;
    return 0;
}
