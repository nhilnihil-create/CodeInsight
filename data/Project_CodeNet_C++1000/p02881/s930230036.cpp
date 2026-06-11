#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin>>n;
	long long res=1e18;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            long long x=n/i;
            res=min(res,(long long)i+x-2);
            
        }
    }
    cout<<res<<endl;
	return 0;
}
