#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	string s;
	cin >> s;
	int count[26] = {0};
	int count2=0;
	for(char x : s){
		count[x-'A']++;
	}
	for (int i = 0;i<26 ;i++){
		if(count[i]==2){
			count2++;
		}
	}
	if(count2 == 2){
		cout << "Yes";
	}
	else
		cout << "No";

	
}	
