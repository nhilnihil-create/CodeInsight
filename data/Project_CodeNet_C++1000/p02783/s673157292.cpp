#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,a,q,r,k;
    cin>>n>>a;
    if(n<=a)
        cout<<1<<endl;
    else {
           q=n/a;
           if(n%a==0)
                cout<<q<<endl;
           else
            cout<<q+1<<endl;
    }
    //cout<<k<<endl;

}
