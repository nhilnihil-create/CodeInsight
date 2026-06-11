#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pi 3.14159265358979323846264338327950L
#define modd 1000000000
#define k 100000000
int main()
{
        int t=1;
        //cin>>t;
        while(t--)
        {
                ll x,amount=100;
                cin>>x;

                for(int i=1; ;i++)
                {
                        amount+=(amount/100);
                        if(amount>=x)
                        {
                                cout<<i<<endl;
                                break;
                        }
                }
        }

}
