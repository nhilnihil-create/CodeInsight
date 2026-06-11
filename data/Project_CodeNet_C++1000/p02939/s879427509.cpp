#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	string div[(int)s.size()];
	int index=1;
	div[0]=s.substr(0,1);
	for(int i=1;i<s.size();i++){
		if(div[index-1]==s.substr(i,1)){
			div[index]=s.substr(i,2);
			i++;index++;
		}else{
			div[index]=s.substr(i,1);
			index++;
		}
	}
	if(div[index-1]==div[index-2])index--;
	puts(index);
}