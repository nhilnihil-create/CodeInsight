#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,sum=0,sub;
    cin>>m>>n;
    int ara[n];
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
        sum=sum+ara[i];
        sub=m-sum;

    }
  if(sub<=0)
  {
      cout<<"Yes"<<endl;
  }
  else{

    cout<<"No"<<endl;
  }


 return 0;
}
