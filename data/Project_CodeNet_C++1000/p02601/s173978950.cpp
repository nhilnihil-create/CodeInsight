#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;

int k, r, g, b;

int main(){
	cin>>r>>g>>b>>k; // b > g > r
	if(b > g && g > r){
		cout<<"Yes"<<endl;
		return 0;
	}
	while(g <= r && k > 0){g *= 2; k--;}
	while(b <= g && k > 0){b *= 2; k--;}
	if(b > g && g > r){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}
