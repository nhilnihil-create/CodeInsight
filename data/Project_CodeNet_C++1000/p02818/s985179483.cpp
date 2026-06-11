#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long A,B,K;
    cin>>A>>B>>K;
    if(K<=A) 
    {
        cout<<A-K<<" "<<B<<endl;
    }
    else if(K<=A+B) 
    {
        cout<<0<<" "<<A+B-K<<endl;
    }
    else 
    {
        cout<<0<<" "<<0<<endl;
    }
    return 0;
}