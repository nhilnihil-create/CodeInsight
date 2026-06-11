#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    int n;
    cin>>n;
    n=n%10;
    if(n==3)
    cout<<"bon"<<endl;
    else if(n==0||n==1||n==6||n==8)
    cout<<"pon"<<endl;
    else
    {
        cout<<"hon"<<endl;
    }
    
}