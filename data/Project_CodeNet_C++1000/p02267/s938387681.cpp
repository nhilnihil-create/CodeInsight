#include <iostream>
using namespace std;
int main()
{
    int s[10001];
    int n,q,i,j,c=0,t;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>t;
        j = 0;
        s[n] = t;
        while(s[j]!=t)
            j++;
        if(j!=n)
            c++;
    }
    cout<<c<<endl;
    return 0;
}