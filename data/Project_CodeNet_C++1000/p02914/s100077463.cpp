#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

// Number of bits to  
// represent int 
#define INT_BITS 62
  
// Function to return 
// maximum XOR subset 
// in set[] 
ll maxSubarrayXOR(ll set[], int n) 
{ 
    // Initialize index of 
    // chosen elements 
    int index = 0; 
  
    // Traverse through all 
    // bits of integer  
    // starting from the most 
    // significant bit (MSB) 
    for (int i = INT_BITS-1; i >= 0; i--) 
    { 
        // Initialize index of 
        // maximum element and 
        // the maximum element 
        ll maxInd = index; 
        ll maxEle = INT_MIN; 
        for (int j = index; j < n; j++) 
        { 
            // If i'th bit of set[j] 
            // is set and set[j] is  
            // greater than max so far. 
            if ( (set[j] & (1LL << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
  
        // If there was no  
        // element with i'th 
        // bit set, move to 
        // smaller i 
        if (maxEle == INT_MIN) 
        continue; 
  
        // Put maximum element 
        // with i'th bit set  
        // at index 'index' 
        swap(set[index], set[maxInd]); 
  
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of set[maxIndex] 
        // with all numbers having 
        // i'th bit as set. 
        for (int j=0; j<n; j++) 
        { 
            // XOR set[maxInd] those 
            // numbers which have the 
            // i'th bit set 
            if (j != maxInd && 
               (set[j] & (1LL << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    } 
  
    // Final result is  
    // XOR of all elements
    ll res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 

  
ll a[200000];
int cnt[65];

int main(){
	int n;cin>>n;
	rep(i,n){
		scanf("%lld",&a[i]);
		rep(j,62){
			cnt[j]+=(a[i]>>j&1);
		}
	}
	ll ans=0;
	rep(j,62){
		if(cnt[j]%2==1){
			ans^=(1LL<<j);
			rep(i,n){
				if(a[i]>>j&1){
					a[i]^=(1LL<<j);
				}
			}
		}
	}
	//~ ll C=0;
	//~ rep(i,n){
		//~ C^=a[i];
	//~ }
	ll S=maxSubarrayXOR(a,n);
	cout<<ans+S*2<<endl;
}