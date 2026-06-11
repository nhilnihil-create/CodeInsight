#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
int main()
{
    INT n;
    cin>>n;
    INT ans=1e13;
    for (int i=1;i<=sqrt(n);i++){
        double a=(double)n/i;
        if(floor(a)==a)
        {
            if(i+n/i<=ans){
                ans=i+n/i;
            }
        }
        
    }
    cout<<ans-2<<endl;
}