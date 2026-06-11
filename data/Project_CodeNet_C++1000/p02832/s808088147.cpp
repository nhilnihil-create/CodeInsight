#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0,s=1,d;
    cin>>n;
    f(i,0,n){
        cin>>d;
        if(d==s){
            ans++;
            s++;
        }
    }
   if(ans==0){
       cout<<-1<<endl;
   }
   else{
       cout<<n-ans<<endl;
   }
    return 0;
}
