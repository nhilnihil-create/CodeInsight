#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define mp make_pair
// GCD inbuilt func: __gcd(a,b)
// LCM formula: (a*b)/__gcd(a,b)

int BS(vector<int> &v, int low, int high, int k){
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==k) return mid;
        else if(v[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
    int k,n;
    cin >> k >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
    	int x;
    	cin >> x;
    	v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(n==0){
    	cout << k;
    	return 0;
    }
    int i=0;
    int ans;
    while(1){
    	int x=BS(v,0,n-1,k-i);
    	int y=BS(v,0,n-1,k+i);
    	if(x==-1){
    		ans=k-i;
    		break;
    	}
    	if(y==-1){
    		ans=k+i;
    		break;
    	} 
    	i++;
    }
    cout << ans;
	return 0;
}
