#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long t,i,j,n,l,m,k,p;

    cin>>n;
    l=n%10;
    if(l==2 || l==4||l==5||l==7||l==9)
    cout<<"hon";
    else if(l==0 ||l==1 ||l==6||l==8)
    cout<<"pon";
    else
    cout<<"bon";
    
    
    
}