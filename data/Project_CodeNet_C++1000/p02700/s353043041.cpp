#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,d;
cin >> a>>b>>c>>d;
while(a>0 || c>0 ){
	c -= b;
	if(c<=0) break;
	a -= d;
	if(a<=0) break;
}
if(c<=0) cout << "Yes" << endl;
else cout << "No" << endl;
}