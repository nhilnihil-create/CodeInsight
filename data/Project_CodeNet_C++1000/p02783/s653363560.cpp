#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long a,b,k=0;
    cin>>a>>b;
    while(a>0){
        a=a-b;
        k++;
        if(a<=0)
         {cout<<k;
         break;}
    }
    return 0;
}
     
   


