#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int main(){
	long long N;
	cin>>N;
	string a=" ";
	while(N){
		N--;
		a+=(char)('a'+(N%26));
		N/=26;
	}
	reverse(a.begin(),a.end());
	cout<<a<<endl;
  return 0;
}