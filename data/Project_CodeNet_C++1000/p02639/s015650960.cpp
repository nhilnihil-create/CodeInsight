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
    int a[5];
    for(int i=0;i<5;i++)cin>>a[i];
    for(int i=0;i<5;i++){
        if(a[i]==0){
            cout<<i+1<<"\n";
            break;
        }
    }
}
