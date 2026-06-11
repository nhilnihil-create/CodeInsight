#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
//#define INF 1000000000000 //10^12:極めて大きい値,∞
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((a+d-1)/d>=(c+b-1)/b){
        cout <<  "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}