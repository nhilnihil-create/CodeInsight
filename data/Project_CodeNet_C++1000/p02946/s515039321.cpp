#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,x,i;
    cin>>k>>x;
    if(k==1)
    cout<<x<<endl;
    else if(k>1)
    {   
        for(i=x-(k-1);i<=x+(k-1);i++)
        {
            cout<<i<<" ";
        }
    }
    
}