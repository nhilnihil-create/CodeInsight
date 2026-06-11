//Atcoder 177B
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	int max=0;
	for(int i=0;i<s.length()-t.length()+1;i++){
		int temp=i;
		int count=0;
		for(int j=0;j<t.length();j++){
			if(s[i]==t[j]){
				count++;
			}
			i++;
		}
		if(count>max) max=count;
		i=temp;
	}
	cout << t.length()-max << endl;
	return 0;
}
