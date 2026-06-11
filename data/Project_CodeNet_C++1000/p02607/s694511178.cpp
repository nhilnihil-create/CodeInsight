#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include<map>
#include <sstream>
#include <deque>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>
const int M = 1e9 + 7;
#define ll long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

//insta  -------  __ansh7
//MSDIAN




int main()
{
    fastio

    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll count=0;

    ll i=0;

    while(i<n)
    {
        if(a[i]%2!=0)
        {
            count++;
        }
        i=i+2;
    }

 

        cout<<count<<"\n";




  

  
    
 



    




    return 0;
}