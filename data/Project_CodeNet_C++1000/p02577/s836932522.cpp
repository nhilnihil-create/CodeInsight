#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	string s;
	int n,sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		sum+=s[i]-48;
	}
	if(sum%9==0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}