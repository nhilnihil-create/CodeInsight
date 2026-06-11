#include <bits/stdc++.h>
using namespace std;
#define ref(i,n) for(int i = 0;i<n;i++)

int main()
{
	string s;
	cin>>s;
	char ch[10] = {0};
	ref(i,4){
		s[i] = tolower(s[i]);
		ch[i] = s[i];
	}
	sort(ch,ch+4);
	if(ch[0] == ch[1] && ch[2] == ch[3] && ch[2] != ch[0])
		cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}