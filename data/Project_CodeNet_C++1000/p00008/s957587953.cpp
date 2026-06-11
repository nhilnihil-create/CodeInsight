#include<iostream>
using namespace std;

int main(){
	int s[60]={0};int n=0,cnt=0;
	while(cin>>s[n++]);n--;
	for(int i=0;i<n;i++){
		for(int a=0;a<10;a++){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					if(s[i]-a-b-c>-1&&s[i]-a-b-c<10)cnt++;
				}
			}
		}
		cout<<cnt<<endl;cnt=0;
	}
	return 0;
}