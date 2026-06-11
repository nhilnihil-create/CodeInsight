#include<bits/stdc++.h>
using namespace std;

#define i64 long long int

i64 id;

int main() {
	cin>>id;
	
	int dig = 1;
	i64 cap = 26LL;
	while(cap < id) {
		id -= cap;
		
		dig++;
		cap *= 26;
	}
	
	for(int i=dig;i>0;i--) {
		cap /= 26;
		char ch = 'a';
		while(id > cap) {
			id -= cap;
			ch++;
		}
		cout<<ch;
	}
	cout<<endl;
	
	return 0;
}