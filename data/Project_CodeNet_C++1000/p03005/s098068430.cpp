#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,dif,sum=0;

    cin>>n>>k;

    dif= n-k;

    if(n<=k){

    cout<<"0"<<endl;

    }

    else if(k==1)
    {
        cout<<"0"<<endl;
    }

    else{

        cout<<dif<<endl;
    }

}
