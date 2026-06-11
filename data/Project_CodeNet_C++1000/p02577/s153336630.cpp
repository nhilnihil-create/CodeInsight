#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	string n;
	int sum=0;
	cin >>n;
	int le = n.length();
	for(int i= 0; i < le;i++)sum +=n[i]-'0';
		
		if(sum% 9 == 0){
			cout << "Yes"<<"\n";
		}else{
				cout <<"No"<<"\n";
			}
			
	
	}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	
	
	
	}
