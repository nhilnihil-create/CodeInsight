#include<bits/stdc++.h>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
   	long long n, a, b;
   	cin>>n>>a>>b;


   	if(!(abs(a-b) & 1)) { // even diff 
   		cout<<(abs(a-b)/2);
   		return 0;
   	}
   	else {
   		long long ans = min(a-1, n-b) + 1 + (b-a-1)/2;
   		cout<<ans;
   		
   	}
	return 0;		
}
