#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>a>>b;
    if(b==1){
       cout<<0<<endl;
    }
    else{
      n=a-b;
      int p=n+1;
      p=p-1;
      cout<<p<<endl;
    }
}
