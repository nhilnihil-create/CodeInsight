#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,sum=0;;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
			sum++;
			i+=2;
		}
	}
	printf("%d\n",sum);
}