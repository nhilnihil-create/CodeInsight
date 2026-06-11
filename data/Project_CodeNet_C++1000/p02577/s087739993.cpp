#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
int main(){
	s ss;
  	cin >> ss;
  	ll sum=0;
  	for( char x:ss){
    sum+=(x-'0');
    }
  	puts( sum % 9 ? "No" : "Yes" );


  	return 0;
}