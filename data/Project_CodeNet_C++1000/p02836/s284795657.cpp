#include<bits/stdc++.h>

using namespace std;   
int main(){
	char s[104];
	int i,len,sum=0;
	cin >> s;
	len=strlen(s);
	for(i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
