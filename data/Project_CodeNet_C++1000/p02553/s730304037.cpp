#include <bits/stdc++.h>
using namespace std;



int main() {

    long a,b,c,d;
    cin>>a>>b>>c>>d;
    long p= max(b*d,a*d);
    long q=max(a*c,b*c);
cout<< max(p,q);
	return 0;
}
