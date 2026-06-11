	#include<bits/stdc++.h>
	using namespace std;
	#define xxx ios::sync_with_stdio(),cin.tie(0),cout.tie(0)
	#define rep(i,n) for(int i=0;i<n;i++)
	#define int long long
	int bp(int a, int b, int m) {
   		a %= m;
   		int res = 1;
    	while (b > 0) {
        	if (b & 1)
            	res = res * a % m;
       		a = a * a % m;
       	 	b >>= 1;
 	    }
    return res;
	}
	int max(int a, int b){
		return (a>b)?a:b;	
	}
	int csb( int n) 
{ 
    int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
	int solve(int x){
		int r=0;
		while(x>0){
			int t=csb(x);
			x%=t;
			r++;
		}
		return r;
	}

	signed main(){
		int test=1;
		//cin>>test;
		while(test--){
			int n;
			cin>>n;
			int a[n];
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			int s=0;
			rep(i,n) {
				for(int j=i+1;j<n;j++){
					s+=a[i]*a[j];
				}
			}
			cout<<s<<endl;
		}
		return 0;
	}