#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<iterator>
#include<vector>
using namespace std;
typedef vector<int> vii;
#define ll long long
#define tt ll t;cin>>t;while(t--)
#define nl endl
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define vec vector<ll>
#define cinv(v) for(auto it:v)cin >> it;
#define coutv(v) for(auto it:v)cout << it <<' ';cout<<endl;
#define so ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
        so;

        string s;
        ll mx=0,ctr=0,i;
        cin>>s;

        for(i=0;i<s.size();i++){
          if(s[i]=='R'){
                    ctr++;
                    mx=max(mx,ctr);
          }
          else ctr=0;
        }
        cout<<mx<<nl;


        return 0;
}

