#include<iostream>
#include<string>
using namespace std;
int main(){
	string w,t;
	int a=0;
	cin>>w;
	for(;;){
		cin>>t;
		int b=t.size();
		if(t=="END_OF_TEXT"){
			cout<<a<<endl;
			return 0;
			}
			for(int i=0;i<b;i++){
				if(t[i]>='A' && t[i]<='Z'){
					t[i]=t[i]+32;
					}
				}
			if(w==t){
				a++;
				}
		}
}

