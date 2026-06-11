#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
string str;
cin>>str;
int N;cin>>N;
for(int i=0;i<N;i++){
	string m;cin>>m;
	if(m=="print"){
		int a,b;
		cin>>a>>b;
		cout<<str.substr(a,b-a+1)<<endl;
	}
	else if(m=="reverse"){
		int a,b;cin>>a>>b;
		string::iterator it;it=str.begin();
		std::reverse(it+a,it+b+1);
	}
	else if(m=="replace"){
		int a,b;string p;
		cin>>a>>b>>p;
			for(int i=0;a<=b;i++){
				str[a]=p[i];
				a++;		
		}
	}
}

return 0;
}