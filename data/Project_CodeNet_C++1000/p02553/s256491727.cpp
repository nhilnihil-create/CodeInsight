#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int main() {
	// your code goes here
	cin >>a>>b>>c>>d;
    
    ll maxi = max(max(a*c,a*d),max(b*c,b*d));
    cout << maxi ;    
       
}