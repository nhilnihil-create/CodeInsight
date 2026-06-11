#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int p,multi=0,r;
    string q;
    cin>>p>>q;
    r=(q[0]-'0')*100+(q[2]-'0')*10+(q[3]-'0');
    multi=p*r;
    multi/=100;
    cout<<multi<<endl;
    return 0;
}

