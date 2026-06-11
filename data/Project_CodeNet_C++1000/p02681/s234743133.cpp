#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string s,t;
	cin >> s >> t;
	t = t.erase(t.size() - 1);
	if(s == t){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}