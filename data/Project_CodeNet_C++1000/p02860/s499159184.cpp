#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
int n,flag=1;

char ss[200];
cin>>n;
for(int i=0;i<n;i++){
cin>>ss[i];
}
if(n%2!=0) {
        flag=0;
}

else if(n%2==0)
{
  for(int i=0;i<(n/2);i++){
    if(ss[i]!=ss[n/2+i]){
        flag=0;
        break;
    }

  }

}
if(flag) cout<<"Yes"<<'\n';
else cout<<"No"<<'\n';
return 0;
}