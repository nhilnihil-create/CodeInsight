// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int a,b;
	cin>>a>>b;
	if( (a == 1 && b == 2) || (a == 2 && b == 1 )){
		cout<<"3"<<endl;
	}else if( (a == 1 && b == 3) || (a == 3 && b == 1 ) ){
		cout<<"2"<<endl;
	}else{
		cout<<"1"<<endl;
	}
}