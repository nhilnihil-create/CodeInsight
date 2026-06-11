#include<bits/stdc++.h>
using namespace std;
typedef long long int i64;
i64  mod= 1000000007;
void inline solve(int tt){

    int a,b;
    cin>>a>>b;
    if(a>9 || b>9)
        cout<<-1<<endl;
    else
        cout<<a*b;


}
int main()
{
    int tt=0,t=1;
    //cin>>t;

    while(t--){solve(++tt);}
}

