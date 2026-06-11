#include<iostream>
#include<map>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,bool> dt;
	string s;
	rep(i,n){
		cin>>s;
		dt[s]=true;
	}
	cin>>n;
	bool door=false;
	rep(i,n){
		cin>>s;
		if(dt[s]){
			if(door){
				cout<<"Closed by "<<s<<endl;
			}else{
				cout<<"Opened by "<<s<<endl;
			}
			door=!door;
		}else cout<<"Unknown "<<s<<endl;
	}
	return 0;
}