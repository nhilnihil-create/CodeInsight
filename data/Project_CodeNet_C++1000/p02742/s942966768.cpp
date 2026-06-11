#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#define endl '\n'
using namespace std;
int main()
{
    long long int h,w;
    cin>>h>>w;
    if(h==1 || w==1)cout<<"1"<<endl;
    else{
            long long m = ceil((long double)(h*w)/2);
        cout<<m<<endl;
    }
    return 0;
}
