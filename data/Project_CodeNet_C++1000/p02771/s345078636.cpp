#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k,i,ans;
    cin>>n>>k>>i;
    if(n==k){
        if(k!=i)ans=1;
        else ans=0;
    }
    else{
        if(n==i||k==i) ans=1;
        else ans=0;
    }
    if(ans)printf("Yes\n");
    else printf("No\n");
   
}