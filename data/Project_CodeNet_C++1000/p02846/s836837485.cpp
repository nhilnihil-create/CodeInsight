#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll T1,T2,A1,A2,B1,B2;cin>>T1>>T2>>A1>>A2>>B1>>B2;
    ll C=T1*A1-T1*B1,D=T2*A2-T2*B2,ans=0;
    if(C+D==0){
    	cout<<"infinity"<<endl;
    	return 0;
    }
    if(C>0){
        if(C+D<0){
            ans=C/(-C-D)*2;
            if(C%(C+D))ans+=1;
        }
    }
    else{
        if(C+D>0){
            ans=-C/(C+D)*2;
            if(C%(C+D))ans+=1;
        }
    }
	cout<<ans<<endl;
    return 0;
}