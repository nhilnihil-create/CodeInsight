#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    long long answer = 0;
    if(k >= n)
    {
        answer = 0;
    }
    else
    {
        for(int i = 0;i<n-k;i++)
        {
            answer += v[i];
        }
    }

    cout<<answer;

    return 0;
}