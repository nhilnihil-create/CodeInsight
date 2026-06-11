#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	bool f=1;
	if(s.size()%2)f=0;
	else{
		for(int i=0;i<s.size();i++){
			if(i%2&&s[i]!='i')f=0;
			if(i%2==0&&s[i]!='h')f=0;
		}
	}
	cout<<(f?"Yes":"No");
}
  

  
