#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool t[1000000]={};
int n=1000000;
int teck(int x){
	int counta=2;
	while(x>counta){
		if(!t[counta]){
			//cout<<counta<<endl;
			int countb=counta;
			while(n>countb){
				//cout<<countb<<" ";
				t[countb]=true;
				countb+=counta;
			}
		}
		counta++;
	}
	int k=x;
	while(t[k]){
		k++;
		//cout<<k<<" ";
		if(k>n){
			return 0;
		}
	}
	return k;
}	
				

int main(){
	int x;
	cin>>x;
	cout<<teck(x)<<endl;
}