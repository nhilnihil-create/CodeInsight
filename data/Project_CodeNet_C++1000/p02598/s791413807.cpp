#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll mod=1000000007;


bool judge(ll x,ll* A,ll N,ll K){
    ll p=0;

    for(int i=0;i<N;++i){
        
        p+=(A[i]-1)/x;
       
    }
     //cout<<"x: "<<x<<" p:"<<p<<endl;

    return p<=K;
}

ll binarysearch(ll* A,ll N,ll K){
    ll ok=1e9;
    ll ng=0;
    while(abs(ok-ng)>1){
          ll mid=(ok+ng)/2;
        if(judge(mid,A,N,K)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;

}



int  main(){
    ll N,K;
    cin>>N>>K;
    ll A[N];

    ll end;

    for(int i=0;i!=N;i++){
        cin>>A[i];

    }
    
    ll ans=binarysearch(A,N,K);
    cout<<ans<<endl;
}
