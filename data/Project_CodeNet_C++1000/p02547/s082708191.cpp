#include<bits/stdc++.h>
using namespace std;
	int main(){
        int t,n,k,c=0,m=INT_MIN;
        cin>>t;
        while(t--){
            cin>>n>>k;
            if(n==k){
                c++;
            }else{
                m=max(c,m);
                c=0;
            }
        }
        m=max(c,m);
        if(m>=3){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}
	}
