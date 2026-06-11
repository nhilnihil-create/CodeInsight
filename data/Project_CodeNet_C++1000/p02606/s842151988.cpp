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

        ll a,b,c;
        cin>>a>>b>>c;

        ll count=0;

        for(ll i=a;i<=b;i++)
        {
            if(i%c==0)
            {
                count++;
            }
        }

        cout<<count<<"\n";




  

  
    
 



    




    return 0;
}