// Atcoder 176 ABC
// A

/*#include <iostream>
using namespace std;
#define ll long long
#define M 1000000007
int main(){
	int n , x, t;
	cin>>n>>x;
	cin>>t;
	if(n%x == 0){
		cout << (n/x)*t << endl;
	}
	else{
		cout << (n/x + 1)*t << endl;
	}
	return 0;

}
*/
/*
// B
#include <iostream>
using namespace std;
#define ll unsigned long long
#define M 1000000007
#define int t; cin>>t; while(t--)
#include <cstring>
// See limits once 
// 0≤N<10^200000
ll digit(string s, ll n){
	ll sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum+=s[i]-'0';
	}
	return sum;
}
int main(){
string s;
cin>>s;
ll n = s.size();
ll ans = digit(s, n);
if(ans == 0){
	cout << "Yes" << endl;
	return 0;
}
if(ans%3 == 0 && ans&1){
	cout << "Yes" <<endl;
}
else{
	cout << "No" << endl;
}
	return 0;
}

*/
#include <iostream>
using namespace std;
#define ll  long long
#define M 1000000007
#define tc int t; cin>>t; while(t--)
#include <cstring>

ll stoolHeight(ll height[], int n){
	ll stool = 0;
	if( n == 1){
		return 0;
	}
	for(int i = 1; i < n; i++){
		if(height[i] < height[i-1]){
			stool+=height[i-1] - height[i];
			height[i] = height[i-1]; 
		}
	}
	return stool;
}
int main(){

	int n;
	cin>>n;
	ll height[n];
	for(int i = 0; i < n; i++){
		cin>>height[i];
	}
	cout << stoolHeight(height, n) << endl;
}















