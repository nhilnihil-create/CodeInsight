#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cin>>s;
int max,count;
max=0;
count=0;
for(int i=0; i<s.length();i++){

	if(s[i]=='R'){
		count++;
		if(max<count){
			max=count;
		}

	}
	else
		count=0;
}
cout<<max;
}
