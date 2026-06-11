#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k, t=100;
    int i=0;
    cin>>k;
    while(t<k){
        t=t+t/100;
        i++;
    }
    cout<<i;


}

