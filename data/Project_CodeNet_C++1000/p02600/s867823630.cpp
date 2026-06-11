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
    int a, t=400;
    cin >> a;

    if(a>=t&&a<=t+199){
        cout<<8;
    }
    t=600;
    if(a>=t&&a<=t+199){
        cout<<7;
    }
    t=800;
    if(a>=t&&a<=t+199){
        cout<<6;
    }
    t=1000;
    if(a>=t&&a<=t+199){
        cout<<5;
    }
    t=1200;
    if(a>=t&&a<=t+199){
        cout<<4;
    }
    t=1400;
    if(a>=t&&a<=t+199){
        cout<<3;
    }
    t=1600;
    if(a>=t&&a<=t+199){
        cout<<2;
    }
    t=1800;
    if(a>=t&&a<=t+199){
        cout<<1;
    }

    return 0;
}