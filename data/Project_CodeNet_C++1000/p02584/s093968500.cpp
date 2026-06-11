#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lld long long int
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   long long int t;
lld x;lld k;lld d;
cin>>x>>k>>d;
x=abs(x);
    lld a= min(k,x/d);
    x=x-(a*d);
    k=k-a;
    if (k% 2== 0) 
        cout<<x<<"\n";
     else 
        cout <<d-x<<"\n";

	return 0;
}

