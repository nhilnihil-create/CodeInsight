#include <bits/stdc++.h>

using namespace std;

int main() {
 	ios_base::sync_with_stdio(0); cin.tie(0);
  	string s,t;
  	cin>>s;
  	t=s;
  	for (int i=0;i<s.length();i++)
    	if (s[i]=='?') t[i]='D';

  	cout<<t<<endl;
}
