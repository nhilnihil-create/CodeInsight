#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int mo[100005];
const int N=1000000007;
int binpow(int x, int y)  
{  
    int res = 1;     // Initialize result  
  
    x = x % N; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % N;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % N;  
    }  
    return res;  
} 

main() {
	int n, k;
	cin>>n>>k;
	mo[1]=1;
	for(int i=2; i<100005; i++){
		int num=i;
		vector<int>f;
		for(int x=2; x*x<=num; x++){
			while(num%x==0){
				num=num/x;
				f.pb(x);
			}
		}
		if(num!=1){
			f.pb(num);
		}
		bool b=0;
		for(int j=0; j<f.size()-1; j++){
			if(f[j]==f[j+1]){
				b=1;
			}
		}
		if(b==1){
			mo[i]=0;
			continue;
		}
		if(f.size()%2==0){
			mo[i]=1;
			continue;
		}
		mo[i]=-1;
	}
	int fin=0;
	
	for(int i=1; i<=k; i++){
		int num=(k/i);
		int ans=0;
		for(int j=1; j<=num; j++){
			int nums=(num/j);
			ans=(ans+mo[j]*binpow(nums, n)+N)%N;
			
		}
		
		fin=(fin+i*ans)%N;
	}
	cout<<fin;
	return 0;
}