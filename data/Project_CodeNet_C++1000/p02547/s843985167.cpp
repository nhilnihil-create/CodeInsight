#include <bits/stdc++.h>
using namespace std;	


int main()
{
	int a;
	cin >>a;
	cin.ignore();
	int count(0);
	while(a--){
		string inp;
		getline(cin, inp);
		if(inp[0]==inp[2])
			count++;
		else
			count  = 0;	
		if(count==3){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
