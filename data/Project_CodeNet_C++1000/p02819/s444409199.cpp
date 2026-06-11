#include<bits/stdc++.h>
using namespace std;
const int m =1e5+50;
bool prime[m];
void find_prime()
{
    prime[1]=true;
    for(int i=2;2*i<=1e5+50;i++)
    {
        prime[2*i]=true;
    }
    for(int i=3;i<=sqrt(1e5+50);i+=2)
    {
        for(int j=3;j*i<=1e5+50;j+=2)
        {
            prime[j*i]=true;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(prime,false,sizeof(prime));
    find_prime();
    for(int i=n;;i++)
    {
        if(!prime[i])
        {
            cout<<i<<'\n';
            return 0;
        }
    }
}