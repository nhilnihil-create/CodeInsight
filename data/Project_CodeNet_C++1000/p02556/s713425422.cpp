#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    long long zmi=2e9,zma=-2e9,wmi=2e9,wma=-2e9;
    cin>>n;
    while(n--){
	    long long x,y;
	    cin>>x>>y;
	    zmi=min(zmi,x+y);
	    zma=max(zma,x+y);
	    wmi=min(wmi,x-y);
	    wma=max(wma,x-y);
    }
    cout<<max(zma-zmi,wma-wmi)<<"\n";
}
 