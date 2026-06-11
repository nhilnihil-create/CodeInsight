#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N; 
    int  D;   
    if(N%2!=0)
    {
        D=(N/2)+1;
        cout<<D;
    }
    else
    {
        D=N/2;
        cout<<D;
    }
}
