#include <iostream>
using namespace std;
 
int main() {
int a,b,i;
string s,sr,ss;
cin >> s >> sr;
cin>>a>>b;
cin >> ss;
if(ss==s)
cout << a-1 << " " << b;
if(ss==sr)
cout<<a<<" "<<b-1;
	return 0;
}
