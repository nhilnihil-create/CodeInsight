#include<iostream>
using namespace std;
const int size=1e5+5;
const int level = 60;
typedef long long int ll;
ll basis[level];
void add(ll mask)
{
    for(int i=level-1;i>=0;i--)
    {
        if(((mask>>i)&1) == 0)
            continue;
        if(!basis[i])
        {
            basis[i] = mask;
            return;
        }
        mask ^= basis[i];
    }
}
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    ll total = 0;
    for(int i=0;i<n;i++)
        cin>>arr[i],total ^= arr[i];
    ll ans = 0;
    for(int i=0;i<level;i++)
    {
        if((total>>i)&1)
        {
            for(int j=0;j<n;j++)
                if((arr[j]>>i)&1)
                arr[j] -= (1LL<<i);
        }
    }
    for(int i=0;i<n;i++)
        add(arr[i]);
    for(int i=level-1;i>=0;i--)
    {
        if(!basis[i])
            continue;
        if((ans>>i)&1) continue;
        ans ^= basis[i];
    }
    cout<<(ans+(ans+total))<<"\n";
    return 0;
}
