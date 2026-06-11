#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::setprecision(11);
    float n;
    cin>>n;
    if(n==1)
    {
        cout<<1.0000000<<"\n";
        return 0;
    }
    if(remainder(n,2)==0)
        cout<<1/2.0<<"\n";
    else
        cout<<((int)(n/2)+1.0)/n<<"\n";

    
}