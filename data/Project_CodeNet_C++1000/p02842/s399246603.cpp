#include <bits/stdc++.h>
using namespace std;
#define ref(i,c,n) for(int i = n;i<c;i++)

int main()
{
    int n,flag;
    cin>>n;
    bool con = true;
    for(int i = 1;i<=n;i++)
    {
        if(i*108/100 == n)
        {
            con = false;
            cout<<i<<"\n";
            break;
        }
    }
    if(con) 
        cout<<":(\n";
    return 0;
}