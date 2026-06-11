#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l=n/2 + ((n%2)>0);
    cout<<fixed<<setprecision(10)<<(l*1.0/n)<<"\n";
    return 0;
}
