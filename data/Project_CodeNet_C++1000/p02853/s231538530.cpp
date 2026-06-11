//
//  main.cpp
//  programs
//
//  Created by Arunesh Sarker on 18/11/19.
//  Copyright © 2019 Arunesh Sarker. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p1;int p2;
    cin>>p1>>p2;
    ll total=0;
    if(p1==3)
        total+=100000;
    if(p1==2)
        total+=200000;
    if(p1==1)
        total+=300000;
    if(p2==3)
            total+=100000;
        if(p2==2)
            total+=200000;
        if(p2==1)
            total+=300000;
    if(total==600000)
        total+=400000;
    cout<<total<<"\n";
    
    
        
        
        
        
        
        
        
    }
    


