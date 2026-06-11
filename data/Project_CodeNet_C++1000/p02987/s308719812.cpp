#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	string s;
	cin >> s;
	map <char,int> count;
	int count2=0;
	for(char x : s){
		count[x]++;
	}
	for (auto it=count.begin(); it != count.end();it++){
		if(it->second==2){
			count2++;
		}
	}
	if(count2 == 2){
		cout << "Yes";
	}
	else
		cout << "No";

	
}	
