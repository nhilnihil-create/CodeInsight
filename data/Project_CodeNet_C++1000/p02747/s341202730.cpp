#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;

int main(){
	cin>>s;
	n = s.length();
	if(n % 2 == 1){
		cout<<"No"<<endl;
	}else{
		for(int i = 1;i <= n - 1;i+=2){
			if(s[i - 1] == 'h' && s[i] == 'i'){
				m++;
			}else{
				break;
			}
		}
		if(m == n / 2){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}
