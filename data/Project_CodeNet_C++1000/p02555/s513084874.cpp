#include<bits/stdc++.h>
using namespace std;
#define ll long long
int d[2005],n;
const int mod=1e9+7;
int main(){
  
    cin>>n;
    d[0]=1;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=i-3;j++){
    		d[i]+=d[j];
    		d[i]%=mod;
    	}
    }
    cout<<d[n];

	return 0;
}
