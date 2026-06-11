#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,left,total=0,b,c;
    cin>>n;
    total+=(n/500)*1000;
    n%=500;
    total+=(n/5)*5;
    cout<<total<<endl;


}
