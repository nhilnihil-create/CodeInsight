#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	string num;
	cin >> num;
	char last = 'a';
	for(char x : num){
		// 3783
		if(x == last){
			cout << "Bad";
			return 0;
		}
		last = x;
	}

	cout << "Good";
	
}	
