//Moh_K_Imar .......
//24/08/2020  ... 5,50.
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a,b;
    cin>>a>>b;
    if((a==1&&b==2)||(a==2&&b==1))cout<<3<<endl;
    else if((a==2&&b==3)||(a==3&&b==2))cout<<1<<endl; 
    else if((a==1&&b==3)||(a==3&&b==1))cout<<2<<endl; 
       
    return 0;
}

