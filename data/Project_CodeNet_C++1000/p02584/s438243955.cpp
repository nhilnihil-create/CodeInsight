#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll t;
t=1;
//cin>>t;
while(t--){
ll x,k,d;
cin>>x>>k>>d;
x=abs(x);
ll ki = x/d;
if(ki>k){
    cout<< x - k*d;
}
else
{
    k-=ki;
    if(k&1)
    cout<<d - x%d;
    else
    cout<<x%d<<endl;
}


}

}