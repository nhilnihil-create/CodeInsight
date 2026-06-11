#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long x[3];
for(int i=0;i<3;i++)
    cin>>x[i];
for(int i=0;i<2;i++){
if(x[i]-x[2]>0){
    x[i]-=x[2];x[2]=0;}
else
   {x[2]=x[2]-x[i];x[i]=0;}
}
cout<<x[0]<<"  "<<x[1]<<endl;

return 0;}
