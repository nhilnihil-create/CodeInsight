#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long h,n;
    cin>>h>>n;
    vector<long long> v(n);
    long long sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
        sum += v[i];
    }

    if(sum >= h)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    

    return 0;
}