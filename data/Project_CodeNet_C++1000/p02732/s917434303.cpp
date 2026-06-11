//
//  main.cpp
//  1234
//
//  Created by Moha Jain on 14/04/20.
//  Copyright © 2020 Moha Jain. All rights reserved.
//
 
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<math.h>
#include <iomanip>
#include <numeric>
#define _USE_MATH_DEFINES
 
using namespace std;
 

 
int main()
{
   long long int n;cin>>n;
    long long int a[n];
    long long int sum = 0;
    map<long long int,long long int>mp;
    for(long long int i=0;i<n;i=i+1){cin>>a[i];mp[a[i]]++;}
    
    for(auto i : mp)
    {
        long long int x = i.second;
        sum +=x*(x-1)/2;
    }
    
    for(int i=0;i<n;i=i+1)
    {
       long long  int ans = sum - (mp[a[i]]-1);
        cout<<ans<<endl;
    }
}



