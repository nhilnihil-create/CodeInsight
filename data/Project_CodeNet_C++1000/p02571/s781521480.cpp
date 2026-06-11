#include <iostream>
#include <string>

using namespace std;

int main(){

	string s,t;
	cin>>s>>t;
	int sn=s.size();
	int tn=t.size();
	int a=0;
	int ans=0;
	for(int i=0;i<sn-tn+1;i++){

		for(int j=i;j<i+tn;j++){
		
			int x=0;
			if(s[j]==t[j-i]){
			
				a++;
			}

		}
		if(a>ans){
		
			ans=a;
		}
		a=0;
	}
	cout<<tn-ans<<'\n';
	return 0;
}

