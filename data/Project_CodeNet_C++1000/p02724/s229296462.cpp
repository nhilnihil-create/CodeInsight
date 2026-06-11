#include<bits/stdc++.h>

using namespace std;
int main(){
    long x,a,b;
    cin >> x;
    a=x/500;
    b=(x-a*500)/5;
    x=a*1000+b*5;
    cout << x << endl;
}