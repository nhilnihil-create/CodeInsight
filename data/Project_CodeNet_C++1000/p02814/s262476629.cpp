#include <bits/stdc++.h>


typedef long long ll;

using namespace std;


const ll mod=1000000007;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
 

int main(){
    int N;
    ll M;
    cin>>N;
    cin>>M;
    ll a;
    ll k=1;
    ll count=-1;
    bool judge=true;


    for(int i=0;i!=N;i++){
        ll cnt=0;
        cin>>a;
        k=lcm(a/2,k);
        
        while(a%2==0){
            a=a/2;
            ++cnt;
        }
        if(count==-1){
            count=cnt;
        }else{
            if(count!=cnt){
                judge=false;
                break;
            }
        }
    }
    //cout<<k<<endl;


    ll ans=(M-M%k)/k;
    if(judge){

    if(ans%2==1){
        cout<<(ans/2+1)<<endl;
    }else{
        cout<<ans/2<<endl;
    }
    }else{
        cout<<0<<endl;
    }
}


