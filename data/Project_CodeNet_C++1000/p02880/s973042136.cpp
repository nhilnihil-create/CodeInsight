#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int n;
 cin>>n;
 if(n==0) cout<<"Yes"<<endl;
 else {
     bool flag=true;
     for (int i = 1; i <= 9; i++) {
         if (n % i == 0) {
             int b=n/i;
             if(b>=1&&b<=9) 
             { flag=false;
                 cout<<"Yes"<<endl;
                 break;
             }

         }

     }
     if(flag) cout<<"No"<<endl;
 }

}