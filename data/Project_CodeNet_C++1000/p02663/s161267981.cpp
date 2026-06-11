#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int t;
    if(a == c)
    t = abs(b - d);
    // else if(a > c){
    //     if(b >= d)
    //     t = (24 - (a - c))*60 + (b - d);
    //     else
    //     t = (24 - ((a - 1) - c))*60 + 60 - (d - b);
    // }
    else if( c > a){
        if(d >= b)
        t = (c -a)*60 + d -b;
        else
        t = (c - 1 - a)*60 + 60 - (b - d);
    }
    cout << t - e ;
}







