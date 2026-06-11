#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
string s, t;
cin >> s >> t;
int a = t.size();
string p = t.erase(a - 1);
if(s == p){
	cout << "Yes" << '\n';
	}
else{
	cout << "No" << '\n';
	}
return 0;
}