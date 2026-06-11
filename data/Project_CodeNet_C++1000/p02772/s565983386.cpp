#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a;
    bool ans=true;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a;
        if(a%2==0&&(a%5!=0&&a%3!=0))
            ans=false;
    }
    cout<<(ans?"APPROVED":"DENIED")<<endl;
}
