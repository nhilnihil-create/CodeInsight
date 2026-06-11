#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n)
    {
        if(n%10==7)
        {
            break;
        }
        n=n/10;
    }
    if(n%10==7)
    cout<<"Yes"<<endl;
    else 
    cout<<"No"<<endl;

}