#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	string s;cin>>s;
	int n = s.length();
	if(n%2==0){
		bool flag = true;
		for(int i=0;i<n;i++){
			if(i%2==0){
				if(s[i]!='h'){
					flag = false; break;
				}
			}
			else{
				if(s[i]!='i'){
					flag = false; break;
				}
			}
		}
		if(flag==true){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	else{
		cout<<"No"<<endl;
	}
} 