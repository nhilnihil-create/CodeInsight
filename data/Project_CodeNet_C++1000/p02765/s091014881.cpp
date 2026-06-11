#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a;
    cin>>n>>m;
    if(n<10)
        {
            a=(100*(10-n))+m;
            cout<<a;
        }
    else
        cout<<m;
}
