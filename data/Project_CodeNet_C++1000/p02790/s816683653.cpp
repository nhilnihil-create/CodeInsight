#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    
    cin>>a>>b;
    
    if(a>=b){
        for(int i=1;i<=a;i++)
        cout<<b;
    }
    else 
     for(int i=1;i<=b;i++)
      cout<<a;
      
    return 0;
}
     
   


