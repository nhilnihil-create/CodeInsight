#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,d,a;
    cin>>n>>d>>a;
    vector<pair<long long,long long>> v(n);
    vector<long long> separate(n);
    for(int i =0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
        separate[i] = v[i].first;
    }

    sort(v.begin(),v.end());
    sort(separate.begin(),separate.end());
    long long rsum = 0;
    vector<long long> baggage(n);
    long long bombs = 0;
    for(int i = 0;i<n;i++)
    {
        long long x = v[i].first;
        rsum += baggage[i];
        long long y = v[i].second;
        y -= rsum;
        if(y <= 0)
        {
            continue;
        }
        long long curr;
        if(y % a == 0)
        { 
            curr = y/a;
            bombs += curr;
        }
        else
        {
            curr = y/a + 1;
            bombs += curr;
        }

        rsum += curr*a;
        
        long long temp;
        temp = x + 2*d;
        auto it = upper_bound(separate.begin(),separate.end(),temp);
        if(it != separate.end())
        {
            int j = it-separate.begin();
            baggage[j] -= curr*a;
        }
    }

    cout<<bombs;

    return 0;
}