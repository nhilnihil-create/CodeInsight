#include <iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
int n,temp,sum=0,m;
cin>>m>>n;
int k[m];
for(int i=1;i<=m ; i++){
    cin>>k[i];
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        if(k[i]<k[j]){
            temp=k[i];
            k[i]=k[j];
            k[j]=temp;

        }
    }
}
for(int i=1;i<=n ; i++){
    sum+=k[i];
}
cout<<sum;
}


