#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a=0,b=0;
    int n,d,x,y,j=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        
        cin>>x>>y;
        a=pow(x,2)+pow(y,2);
        b=sqrt(a);
        if(b<=d){
             j++;
        }
    }
    cout<<j;
    


}