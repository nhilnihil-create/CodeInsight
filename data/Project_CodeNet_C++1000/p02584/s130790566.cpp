#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int x,k,d;

	cin>>x>>k>>d;
    x=abs(x);
    if(x>0 && (x/d)>=k){
        long long qq=x/d;
        x=x-(k)*d;
        cout<<x;
        return 0;
    }
    long long y=x/d;
    x-=y*d;
    k-=y;
    if(k%2==0)
        cout<<abs(x);
    else
        cout<<min(abs(x-d),abs(x+d));
    return 0;
}
