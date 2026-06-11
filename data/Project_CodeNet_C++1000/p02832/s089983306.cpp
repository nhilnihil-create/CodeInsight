#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,c=1,b=0;
    cin>>n;
 
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        if(a==c) c++;
        else b++;
        
    }
        
    if(c==1) cout<<"-1\n";
    else cout<<b << "\n";
    
	return 0;
}
