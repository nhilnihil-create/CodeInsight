#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
long long solve(long long x,long long k,long long d){

    long long ans;
    if(x<d){
        if(k%2==1){
            ans=abs(x-d);
        }
        else{
            ans=x;
        }
    }
    else if(x==d){
        if(k%2==1){
            ans=0;
        }
        else{
            ans=x;
        }
    }
    else{
        if((long double)x/d>k){
            ans=abs(x-d*k);
        }
        else{
            long long res=x%d;
            long long l=x/d;
            if((k-l)%2==0){
                ans=res;
            }
            else{
                ans=abs(res-d);
            }
        }
    }


    return ans;
}
int main(){
    long long x,k,d;
    cin>>x>>k>>d;
    //x=1;
    //d=5;
    //k=20;
    x=abs(x);
    
    cout<<solve(x,k,d)<<endl;



    return 0;

}
/*


*/
