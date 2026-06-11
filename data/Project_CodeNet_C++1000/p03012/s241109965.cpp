#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,sum,var;
    sum=0;
    var=0;
    cin>>N;
    int Wgt[N];
if(N>=2&&N<=100){
    for(int i=0;i<N;i++)
    {
        cin>>Wgt[i];
        sum=sum+Wgt[i];
    }
    int tot=sum;
    for(int i=0;i<N;i++)
    {
        var=var+Wgt[i];
        tot=min(tot,abs(var-(sum-var)));
    }

    cout<<tot;
}
    
return 0;
}