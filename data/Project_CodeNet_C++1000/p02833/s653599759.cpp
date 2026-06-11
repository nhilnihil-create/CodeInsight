#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long c=0;
    if(n&1){
        cout<<0<<endl;
        return 0;
    }
    for(long long i=10;i<=n;i*=5){
        c+=n/i;
    }
    cout<<c<<endl;
    
	return 0;
}
