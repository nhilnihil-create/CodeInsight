#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int a;
	a = 0; 
	int d = s.size();
	for(int i=0;i<d;i++){
		for(int j=i+1;j<d;j++){
			if(s[i]==s[j]){
				a++;
			}
		}
	}
	if(a==2){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}
