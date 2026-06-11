#include<bits/stdc++.h>
    using namespace std;
    #define 	ll 			long long
    #define 	w(t)		int t; cin>>t; while(t--)  
	#define 	AsmShuvo()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
			
    int main()
    {
    AsmShuvo()
    	
    	long long a, b, k;
		cin >> a >> b >> k;

		if(a>=k){
 		cout<<a-k<<' '<<b<<endl;
 		}
 		
		else if(a+b>=k){
 		cout<<0<<' '<<b-(k-a)<<endl;
 		}
 		
		else{
 		cout<<0<<' '<<0<<endl;
 		}

	}
	
