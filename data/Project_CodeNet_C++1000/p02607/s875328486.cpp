#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,temp,count=0;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>temp;
        if((i%2)==0&&(temp%2)==1)
            ++count;
    }
    cout<<count;
    return 0;
}
