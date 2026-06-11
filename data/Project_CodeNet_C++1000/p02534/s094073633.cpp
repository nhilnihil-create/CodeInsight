/*
    Author : MAHIM_JU_CSE
    From   : CSE,JU,Batch:47
    Date   : 27.09.2020
*/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX 1e19
#define MIN -1e19
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define mk make_pair
#define pii pair<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define pli pair<long long int,int>
#define pll pair<long long int,long long int>
#define mii map<int,int>
#define msi map<string,int>
#define mis map<int,string>
#define mli map<long long int,int>
#define mll map<long long int,long long int>
#define qi queue<int>
#define qll queue<ll>
#define dqll deque<ll>
#define dqi deque<int>
#define memset(array,value) memset(array,value,sizeof(array))
#define endl "\n"
#define LCM(a,b) a*b/__gcd(a,b)
#define GCD(a,b) __gcd(a,b)
#define Sort(name) sort(name.begin(),name.end())
#define SorT(name) sort(name.rbegin(),name.rend())
const double pi = acos(-1.0);
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int fact(int n)
{
    return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
void sieve(ll n)
{
    bool check[n+1];
    memset(check,true);
    for(ll i=2; i*i<=n; i++)
        if(check[i]==true)
            for(ll j=i*i; j<=n; j+=i)
                check[j]=false;
    for(ll i=2; i<=n; i++)
    {
        if(check[i]==true)
        {
            cout<<i<<" ";
        }
    }
}

bool isprime(ll n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0||n%3==0)
        return false;
    for(ll i=5; i*i<=n; i=i+6)
        if(n%i==0||n%(i+2)==0)
            return false;
    return true;
}


int main()
{
    fio;
    ll t;
    cin>>t;
    while(t--)
    {
        cout<<"ACL";
    }
    return 0;
}
