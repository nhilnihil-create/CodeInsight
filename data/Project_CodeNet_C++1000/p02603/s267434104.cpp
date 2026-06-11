#include<bits/stdc++.h>
using namespace std;
int a[110];
#define int long long int
main(){
    int i,n,k,ans=1000;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
	for(i=1;i<=n;i++){
		if(a[i+1]>a[i]){
			k=(ans)/a[i];
          ans=ans%a[i]+(k*a[i+1]);
      	}
   	}
	cout<<ans<<"\n";
    return 0;
}
