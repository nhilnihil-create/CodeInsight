#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++){
if(i*j==n)
    {cout<<"Yes"<<endl;return 0;}
if(i==9&&j==9)
    cout<<"No"<<endl;
}
return 0;}
