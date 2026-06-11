#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int>vb;
bool prime[10000001]={true};
void Seive(int n)
{
    memset(prime, true, sizeof(prime)); 
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
        for(int j=i*i;j<=n;j+=i)
        prime[j]=false;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
        vb.push_back(i);
    }
}
int bs(int e)
{
    int lo = 0, hi = vb.size() - 1;
        while (hi > lo) {
            int mid = (lo + hi) / 2;
            if (vb[mid] >= e) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
}

int main()
{
    Imposter
    
    Seive(1e7);
    //for(int i=0;i<vb.size();i++)
    //cout<<vb[i]<<" ";
    
    int x;
    cin>>x;
    cout<<vb[bs(x)]<<endl;
    
}
