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
	int d1,d2,m1,m2;
	cin>>m1>>d1;
	cin>>m2>>d2;
	if( (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) && (d1 == 31)){
		cout<<"1"<<endl;
	}else if( m1 == 2 && d1 == 28 ){
		cout<<"1"<<endl;
	}else if(( m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11 ) && (d1 == 30) ){
		cout<<"1"<<endl;
	}else{
		cout<<"0"<<endl;
	}
}