#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define p 3165
#define mx 10000005
ll divi[mx];
void divisor(){
    ll i,j;
   for( i=1;i<=mx;i++){
    for( j=i;j<=mx;j+=i)divi[j]++;
   }
}
int main(){
    divisor();
    int n;
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        sum+=(i*divi[i]);
    }
    cout<<sum<<endl;
    return 0;
}
