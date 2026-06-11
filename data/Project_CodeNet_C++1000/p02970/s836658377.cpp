#include <bits/stdc++.h>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    long N,D;
    double t;
    cin>>N>>D;
    t=N/(2.0*D+1);
    if(t==(int)(t))
    cout<<t<<endl;
    else
        cout<<(int)(t+1)<<endl;
    return 0;

}
