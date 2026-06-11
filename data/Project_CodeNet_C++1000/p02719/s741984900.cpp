#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x,k;
    cin>>x>>k;
    if(x%k==0)
    {
        cout<<0;
    }
    else
    {
        long long a,b,c;
        a = x%k;
        b = x/k;
        c = abs(x- k*(b+1));
        //<<a<<" " <<b<<endl;
        cout<<min(a,c);
    }
    return 0;
}
