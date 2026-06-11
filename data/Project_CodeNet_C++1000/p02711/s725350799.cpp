
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;



int main(void)
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

   int n;
   cin>>n;
   for(int i=0;i<3;i++)
   {
       if(n%10==7)
       {
           cout<<"Yes"<<endl;
           return 0;
       }
       n/=10;
   }
   cout<<"No"<<endl;


}

