#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int min=t.length();
	for(int i=0;i<s.length()-t.length()+1;i++){
		int count=0;
		for(int j=0;j<t.length();j++){
			// cout << s[i+j] << " " << t[j] << endl;
			if(s[i+j]==t[j]){
				count++;
			}
			// cout << count <<endl;
		}
		if(min>t.length()-count){
			min=t.length()-count;
		}
	}
	cout << min << endl;
	return 0;
}