#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n,x,y,min=9999999999999;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            x=i;
            y=n/i;
            x-=1;
            y-=1;
            if((x+y)<min)
                min=x+y;
        }
    }
    cout<<min<<endl;
    return 0;
}