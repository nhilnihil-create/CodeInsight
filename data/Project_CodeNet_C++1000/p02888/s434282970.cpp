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
			rep(i,n) cin>>a[i];
			sort(a,a+n);
			int  s=0;
			//for(int i=0;i<n;i++){ cout<<a[i]<<" ";}
				//cout<<endl;
			rep(i,n){
				for(int j=i+1;j<n;j++){
					int lt=a[i]+a[j];
					int ind=upper_bound(a,a+n,lt-1)-a;
					if(ind==n) ind=n-1;
					if(ind<=j) continue;
					if  (a[ind]<lt){ s+=ind-j;}//cout<<i<<" "<<j<<" "<<ind<<endl;}
					else if(a[ind-1]<lt && ind-1 >j){ s+=ind-j-1;}//cout<<i<<" "<<j<<" "<<ind<<endl;}

				}
			}
			cout<<s<<endl;
		}
		return 0;
	}