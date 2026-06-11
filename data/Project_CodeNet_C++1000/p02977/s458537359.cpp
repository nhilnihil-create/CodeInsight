#include<bits/stdc++.h>
using namespace std;

long long n,k,pot;

int main(){

	cin>>n;
	
	k=n;
	pot=1;
	
	while(k%2==0){
        k/=2;
        pot*=2;
    }
	
	if(n<=2 || k==1)cout<<"No\n";
	else{
	    
	    cout<<"Yes\n";
	    
	    cout<<n+1<<" 3"<<endl;
	    
	    for(int i=3;i<=n;i+=2){
	        cout<<i-1<<" "<<1<<endl;
	        cout<<i<<" "<<i-1<<endl;
	        cout<<n+i<<" "<<1<<endl;
	        cout<<n+i-1<<" "<<n+i<<endl;
        }
        
        if(n%2==0){
            cout<<n+pot+1<<" "<<n<<endl;
            cout<<2*n<<" "<<(n^pot)<<endl;
	    }
	   
    }

return 0;
}
