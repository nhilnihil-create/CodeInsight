#include<bits/stdc++.h>
using namespace std;
	int main(){
        int t,n,k,c=0,m=INT_MIN;
        cin>>t;
        while(t--){
            cin>>n>>k;
            if(n!=k){
                m=max(c,m);
                c=0;
            }else{
                c++;
            }
        }
        m=max(c,m);
        if(m<3){cout<<"No"<<endl;}
        else{cout<<"Yes"<<endl;}
	}
