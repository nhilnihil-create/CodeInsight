#include <iostream>
#include <algorithm>
using namespace std; 
long long s[4];
int main(int argc, char** argv) {
long long a,b,c,d;
cin>>a>>b>>c>>d;
s[0]=a*c;
s[1]=a*d;
s[2]=b*c;
s[3]=b*d;
sort(s,s+4);
cout<<s[3]; 
	return 0;
}