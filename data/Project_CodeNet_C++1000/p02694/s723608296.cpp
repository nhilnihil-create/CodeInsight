#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    long long ct=100;
    cin>>a;
    long long u=100;
    int t=0;
    while(u<a){
        u+=u/100;
        t++;
    }
    cout<<t;
}
