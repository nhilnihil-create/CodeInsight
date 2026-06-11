#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x;
	cin>>x;
	vector<char>arr;
	while(x>0){
		x--;
		arr.push_back((char)('a'+x%26));
		x/=26;
	}
	for(int i=arr.size()-1; i>=0; i--) cout<<arr[i];
	
}