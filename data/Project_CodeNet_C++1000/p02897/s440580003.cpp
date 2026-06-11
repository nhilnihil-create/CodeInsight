#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    double n;
    cin>>n;
    if((int)n%2==0)cout<<fixed<<setprecision(10)<<(n/2)/n<<endl;
    else {
        double p = (int)n/2+1;
        cout<<fixed<<setprecision(10)<<(p/n)<<endl;
    }
    return 0;
}
