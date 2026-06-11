#include <bits/stdc++.h>
using namespace std;
long f(long x,long y){
    long a = x,b = y;
    while(y != 0){
        long c = y;
        y = x%y;
        x = c;
    }
    return a*b/x;
}
int main(){
    long a,b,x,y;
    cin>>a>>b>>x>>y;
    long X = b/x - a/x;
    if(a%x == 0)X++;
    long Y = b/y - a/y;
    if(a%y == 0)Y++;
    long Z = b/f(x,y) - a/f(x,y);
    if(a%f(x,y) == 0)Z++;
    cout << b-a - (X + Y - Z) + 1 << endl;
}