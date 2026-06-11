#include<bits/stdc++.h>
using namespace std;
int main(void){
pair<int,int>y,z;
y=make_pair(500,1000);
z=make_pair(5,5);
int x,sum=0;cin>>x;
while(true){
    if(x-y.first>=0)
        {x-=y.first;sum+=y.second;}
    else
        break;
}
while(true){
    if(x-z.first>=0)
        {x-=z.first;sum+=z.second;}
    else
        break;
}
cout<<sum<<endl;


return 0;}
