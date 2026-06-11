#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;



int main(){
    long double a, b, c, h, m;
    cin>>a >>b >>h >>m;
    long double rad = 2 * M_PI *((h + m / 60) / 12 - m / 60);
    cout<< fixed << setprecision(10) <<sqrt(a * a + b * b - 2 * a * b * cos(rad))<<endl;
}
