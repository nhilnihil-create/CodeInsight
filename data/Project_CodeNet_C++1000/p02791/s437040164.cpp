#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,c=1,mx;
    cin>>n;
 for (int i=0;i<n;i++ )
 {
     cin>>a;
     if(i==0){mx=a;}
     else {
    if(a<mx){c++;mx=a;}
     }
 }
    cout<<c<<endl;
}
