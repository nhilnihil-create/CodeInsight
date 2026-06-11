#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
const int MOD = 1000000007;


typedef long long int ll; 
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

void floatOutPutSetup(){
    cout << fixed;
    cout << setprecision(10);
}

int main(){
    int r,g,b,k;
    cin>>r>>g>>b>>k;

    while(k){
        if(r>=g){
            g*=2;
            k--;
        }else{
            break;
        }
    }
    while(k){
        if(g>=b){
            b*=2;
            k--;
        }else{
            break;
        }
    }

    if(r<g&&g<b){
        cout<<"Yes";
    }else{
        cout<<"No";
    }


    return 0;
}