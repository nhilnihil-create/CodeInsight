#include<bits/stdc++.h>
using namespace std;
int main(void){
int a,n;cin>>a>>n;
int x[n];
for(int i=0;i<n;i++)
    cin>>x[i];
for(int i=0;i<n;i++)
    {a-=x[i];
    if(a<0)
        {cout<<-1<<endl;return 0;}}
cout<<a<<endl;

return 0;}
