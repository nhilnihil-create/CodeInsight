#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll= long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    int P[N];
    rep(i,N){
        P[i]=i;
    }
    int x[N],y[N];
    rep(i,N){
        cin>>x[i]>>y[i];
    }
    double ans=0,cnt=0;
    
    do {
        rep(i,N-1){
            ans+=sqrt(pow(abs(x[P[i]]-x[P[i+1]]),2)+pow(abs(y[P[i]]-y[P[i+1]]),2));
        }
        cnt++;
    } while(next_permutation(P,P+N));
  
  
    double ave=(double) ans/cnt;
    cout << fixed << setprecision(10);
    cout<<ave<<endl;
    }
    
    
    
    
    
  
 
 


