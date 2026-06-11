#include<bits/stdc++.h>

using namespace std;

long long int attack(long long int h){
	if(h==1)
		return 1;
	else {
		h=attack(h/2);
		h*=2;
		h+=1;
		return h;
	}
}
int main(){
	long long int h;
	cin >> h;
	long long int res=attack(h);
	cout<<res<<"\n";
}