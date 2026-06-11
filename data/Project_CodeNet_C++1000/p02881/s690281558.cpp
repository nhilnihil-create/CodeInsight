#include<bits/stdc++.h>
using namespace std;
typedef long long int i64;
i64  mod= 1000000007;
void inline solve(int tt){

    i64 n;
    cin>>n;
    i64 mini=1e13;
    for(int i=1;i<=sqrt(n);i++)
    {
        if((n%i) == 0)
        {
            i64 t=n/i;
            i64 p=i;
            mini=min(mini,(p+t-2));
        }
    }
    cout<<mini<<endl;

}
int main()
{
    int tt=0,t=1;
    //cin>>t;

    while(t--){solve(++tt);}
}

