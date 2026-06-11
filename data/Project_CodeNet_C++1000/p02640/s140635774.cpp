//
//  main.cpp
//  codechef
//
//  Created by Krishnam Srivastava on 08/02/20.
//  Copyright © 2020 Krishnam Srivastava. All rights reserved.


#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
#include<stack>
#include<string>
#include<climits>
#include<cmath>
#include<iomanip>
#include<unordered_map>
#include<set>
//#include<utility>
#define MAX 2147483647
typedef long long int lli;
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(y%2!=0)cout<<"No"<<"\n";
    else{
        if((y>4*x)||(y<2*x))cout<<"No"<<"\n";
        else{
            cout<<"Yes"<<"\n";
        }
    }
}
