#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool ok=true;
    while(n--)
    {
        int a;
        cin>>a;
        if(a%2==0)
        {
            if(a%3==0 || a%5==0)
                    continue;
            else
                    ok=false;
        }
    }
    if(ok==true)
        cout<<"APPROVED"<<endl;
    else
        cout<<"DENIED"<<endl;
}
