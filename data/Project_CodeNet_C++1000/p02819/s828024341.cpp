#include<bits/stdc++.h>
using namespace std;
int is_prime(int x)
{
    int i;
    if(x==2){
        return 1;
    }
    if(x%2==0){
        return 0;
    }
    for(i=3;i<=sqrt(x);i=i+2){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
   int x;
   cin>>x;
   while(1){
    if(1==is_prime(x)){
        cout<<x<<endl;
        break;
    }
    else{
        x++;
    }
   }
   return 0;
}
