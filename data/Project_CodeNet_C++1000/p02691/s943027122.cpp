/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<ll,ll> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n;
    cin>>n;
    ll a[n];
    map<ll,ll> mp;
    f(i,n){
        cin>>a[i];
        mp[i+1+a[i]]++;
    }
    ll ct=0;
    f(i,n){
        int k = (i+1-a[i]);
        if(mp.find(k)!=mp.end()){
            ct+=mp[k];
        }
    }
    
    cout<<ct<<endl;
}