#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long k,q;
    cin>>k>>q;
    vector<long long> d1(k);
    for(long long i =0; i<k; i++)
        cin>>d1[i];
    while(q--)
    {
        long long n,x,m;
        cin>>n>>x>>m;
        vector<long long> d(k);
        for(long long i=0; i<k; i++)
            d[i] = d1[i]%m;
        long long sum = 0;
        for(long long int i=0; i<k; i++)
            sum+=d[i];
        long long presum =0;
        for(long long int i=0; i<= (n-2)%k; i++)
            presum+=d[i];
        sum = sum*((n-2)/k) + presum;
        long long a = sum + x;
        long long quot = a/m - x/m;

        long long counti =0;
        for(int i =0; i<k; i++)
        {
            if(d[i]==0)
                counti++;
        }
        counti*=((n-2)/k);
        long long count2 =0;
        for(int i =0; i<=(n-2)%k; i++)
        {
            if(d[i]==0)
                count2++;
        }
         count2+=counti;


       cout<<n-1-count2-quot<<"\n";
    }
}
