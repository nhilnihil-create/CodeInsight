#include <bits/stdc++.h>
using namespace std;
int main(){
	int64_t N,ans=0,sum=0,che=0;
    cin>>N;
    vector <int64_t>A(N+1),B(N+1),S(N+2);
    for(int i=0;i<=N;i++){
    	cin>>A[i]; 
        B[i]=0;
        sum+=A[i];
    }
    int64_t s=1,p,q;
    S[0]=1;
    for(int i=N;i>=0;i--){
    	if(i==N) B[i]=A[i];
        else B[i]=A[i]+B[i+1];
    }
    for(int i=0;i<=N;i++){
        if(A[N]==0){
        che=1;
        break;
        }
        if(A[0]==1&&N==0){
        	che=2;
            break;
        }
    	if(s<A[i]) {
          			che=1;
                    break;
        			}
        if(i!=N&&s==A[i]) {
          che=2;
          p=i; 
          break;
        }
      	if(s>A[i]){
        	s=(s-A[i])*2;
            if(i!=N&&s>=B[i+1]){
              q=i+1;
              che=3;
              break;
            }
            if(i==N) {
              s=A[i];
            }
            S[i+1]=s;
        }
    }
	if(che==1) cout<<-1;
    if(che==2) {
    	if(N==0) cout<<1;
        else cout<<-1;
    }
    if(che==3){
    	for(int j=0;j<q;j++){
        	ans+=S[j];
        }
        for(int j=q;j<=N;j++){
        	ans+=B[j];
        }
    	cout<<ans;
    }  
    if(che==0){
    	for(int j=0;j<=N;j++){
        	ans+=S[j];
            
        }
        cout<<ans+1;
    }
  
}
