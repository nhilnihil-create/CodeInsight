#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;


int main(){
    ll A,B,N;
    cin>>A>>B>>N;
    
    ll ans=0;
    if(B==1){
       ans=0;
    }else if(N<B){
        ll a=floor(A*N/B);
        ll b=floor(N/B);
        ans=a-A*b;
    }else{
        ll a=floor(A*(B-1)/B);
        ll b=floor((B-1)/B);
        ans=a-A*b;
    }
    
      cout<<ans<<endl;
    /*
    ll ans2=0;
    
    
    for(int x=1;!(x%B==0)&&(x<=N);++x){
        ll a=(A*(x))/B;
        ll b=(x)/B;
        ll c=a-A*b;
        //cout<<"x:"<<x<<" a:"<<a<<" "<<"-A*x/B:"<<A*b<<" ans:"<<ans<<endl;
        ans2=ans2>=c?ans2:c;
    }

    cout<<"ans2: "<<ans2<<endl;
     */
}
