//#include<bits/stdc++.h>
#include<iostream>
//#include<map>
//#include<vector>
//#include<algorithm>
#define ll long long
#define endl "\n"
using namespace std;
//map<int,int>m;
/*
bool isprime[500+5];
vector<int>pf;
vector<int>arr;

void sieve()   // O(N lg lg N)
{
    int n=500; //sqrt of 2^31
    for(int i = 0; i <= n; i++)
    {
        isprime[i] = true;
    }
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i <= n; i++)
    {
        if(isprime[i] == true)
        {
            for(int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(isprime[i])
        {
            pf.push_back(i); //store the prime numbers upto 10^8
        }
    }
} */
bool check(int n)
{
    int r;
    while(n>0)
    {
        r=n%10;
        if(r==7)
        {
            return true;
        }

        n=n/10;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);//NULL;
    // sieve();
    int t;
    cin>>t;
    if(check(t))
 {
     cout<<"Yes"<<endl;
 }
 else
 {
     cout<<"No"<<endl;
 }



}


