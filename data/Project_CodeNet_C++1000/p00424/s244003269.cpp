#include<iostream>
using namespace std;
main(){
	int n,m;
	while(cin>>n,n){
		char a,b,l[62] = {0};
		while(n--)
			cin >> a >> b,l[a > 96?a - 97:a > 64?a - 39:a > 47?a + 4:0] = b;
		cin >> m;
		string s = "";
		while(m--){
			cin >> a;b = l[a > 96?a - 97:a > 64?a - 39:a > 47?a + 4:0];if(b==0)b = a;s+=b;}
		cout << s << endl;
	}
}