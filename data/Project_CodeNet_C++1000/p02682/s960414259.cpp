#include<bits/stdc++.h>
using namespace std;
const int n=3;
int x[3];
int main(void){
pair<int,int>x[3];
for(int i=0;i<3;i++)
    {cin>>x[i].first;x[i].second = 1-i;}
int k,sum=0;cin>>k;
for(int i=0;i<3;i++){
    if(x[i].first-k>=0)
        {sum+=k*x[i].second;break;}
    else
        {sum+=x[i].first*x[i].second;k-=x[i].first;}
}
cout<<sum<<endl;
return 0;}
