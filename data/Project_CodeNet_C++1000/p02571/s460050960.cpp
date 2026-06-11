#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string S,T;
	cin>>S>>T;
	int answer=T.length();
	for(int i=0;i<=S.length()-T.length();i++){
		int now=0;
		for(int j=0;j<T.length();j++){
			if(S[i+j]!=T[j]){
				now++;
			}
		}
		answer=min(now,answer);
	}
	cout<<answer;
	return 0;
}
