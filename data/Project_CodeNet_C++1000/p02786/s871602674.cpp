#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long h;
    cin>>h;
    long long answer;
    for(long long i = 0;i<=50;i++)
    {
        if((1ll<<i) > h)
        {
            answer = (1ll<<i) - 1;
            break;
        }
    }

    cout<<answer;

    return 0;
}