#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,R,I;
    cin>>N;
    cin>>R;
    if(N<=10)
    { 
       I=R+(10-N)*100;
       cout<<I;
    }
    else
    {
       cout<<R;
    }
}