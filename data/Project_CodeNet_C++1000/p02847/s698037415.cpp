#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int mod=1e9+7;
string s;
int ans;
int main(){
	 cin>>s;
	 if(s == "SAT")ans = 1;
	 else if(s=="MON"){
	 	ans = 6;
	 }
	 else if(s=="TUE"){
	 	ans = 5;
	 }
	 else if(s=="WED"){
	 	ans = 4;
	 }
	 else if(s=="THU"){
	 	ans = 3;
	 }
	 else if(s=="FRI"){
	 	ans = 2;
	 }
	 else if(s=="SUN"){
	 	ans = 7;
	 }
	 cout<<ans;
 }