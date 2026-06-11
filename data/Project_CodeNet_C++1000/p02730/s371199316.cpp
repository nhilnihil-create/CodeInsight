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
    string s;cin>>s;
    
    int n = (int)s.length();
    
    string t = s;
    reverse(t.begin(),t.end());
    if(t!=s){cout<<"No"<<endl;return 0;}
    string u = s.substr(0,n/2);
    string v = u;
    reverse(v.begin(),v.end());
    if(v!=u){cout<<"No"<<endl;return 0;}
    
    string w = s.substr((n+3)/2 -1);
    string x = w;
    reverse(x.begin(),x.end());
    if(x!=w){cout<<"No"<<endl;return 0;}
    
    cout<<"Yes"<<endl;
}


