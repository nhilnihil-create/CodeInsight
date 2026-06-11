#include<bits/stdc++.h>
using namespace std;
#define ll  long long
int main()
{
        ll a,b,sum=1,f=0;
        cin>>a>>b;
        for(int i=20;i<=b;i++)
        {
                ll  c=i,flag=0;
                while(1){
                      ll b=(c%10) ;
                      if(b<2) flag=1;
                      sum*=b;
                      c=(c/10);
                      if(c==0) break;
                }
                if(flag==0){
                if(sum<=a) f++;
                }
                sum=1;
        }
        cout<<f<<endl;
}
