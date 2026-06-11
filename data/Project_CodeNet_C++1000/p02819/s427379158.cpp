  //Name : Rupa Dey
  //Date : 05 September 2020
//joi sri gour hori gobindo...
//gobindo ja hobe vlor jonnoi hobe..
#include<bits/stdc++.h>
#define ll long long
#define d double
#define ld long double
#define vi vector<int>
#define vul vector<ull>
#define vl vector<ll>
#define pb push_back
#define si set<int>
#define sl set<ll>
#define yes cout<<"YES\n"<<endl
#define no cout<<"NO\n"<<endl
#define ys cout<<"Yes\n"<<endl
#define n0 cout<<"No\n"<<endl
#define test cin>>t; while(t--)
//#define for(i,a,n) for(i=a;i<n;i++)
#define mp make_pair
#define ft first
#define sc second
#define gp ' ';
#define MAX 9999999
#define MOD 1000000007
#define nd endl
using namespace std;
bool prime(int);

/*bool prime(int a)
{
    int cnt=0,i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) cnt++;
    }
    if(cnt==0) return true;
    else  return false;
}*/
bool isPrime(ll a)
{
    ll i;
    if(a==2 || a==3) return true;
    if(a%2==0 || a%3==0) return false;
    for(i=5;i*i<=a;i++)
    {
        if(a%i==0 || a%(i+2)==0) return false;
    }
    return true;
}
/*int nxtPrime(ll x)
{
    if(x==2) return 2;
    if(x==3) return 3;
    ll p = x;
    bool prime = false;

    while(!prime)
    {
        p++;
    if(isPrime(p)) prime = true;
    }
    return p;
}*/
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i;
  //  cin>>n;
    //cout<<nxtPrime(n);
    for(cin>>n;;n++)
    {
        if(isPrime(n))
            cout<<n,exit(0);
        //return 0;
    }

}
//hare krishna...
//hey gobindo kripa koro......
//only gobindo exists..^..
