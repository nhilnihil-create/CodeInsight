#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll s;
    
    cin>>s;
   
    ll x=1000000000,y=1;
    
   
    int x1=(x-s%x)%x;
     int y1=(s+x1)/x;
    cout<<0<<" "<<0<<" "<<x<<" "<<y<<" "<<x1<<" "<<y1;
  
}
