#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const long inf=1e9;
int main(){
	long T[2];long A[2],B[2];
	cin>>T[0]>>T[1];
	cin>>A[0]>>A[1];
	cin>>B[0]>>B[1];
    if(A[0]>B[0]){ swap(A[0],B[0]); swap(A[1],B[1]); }
	long s=T[0]*(A[0]-B[0])+T[1]*(A[1]-B[1]);
	if(s<0) cout<<0<<endl;
	else if(s==0) cout<<"infinity"<<endl;
	else{
        long t=-T[0]*(A[0]-B[0]);//cout<<s<<" "<<t<<endl;
        if(t%s) cout<<2*(t/s)+1<<endl;
        else cout<<2*(t/s)<<endl;
    }
}