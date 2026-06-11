#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a,b;
int main(void){
    cin>>n>>a>>b;
    if((b-a)%2==0){
        cout<<abs(b-a)/2<<endl;
    }else{
        if(n-b<a-1){
            cout<<(n-b)+1+(n-a-(n-b+1))/2<<endl;
        }else{
            cout<<(a-1)+1+(b-(a-1+1)-1)/2<<endl;
        }
    }
    
}
