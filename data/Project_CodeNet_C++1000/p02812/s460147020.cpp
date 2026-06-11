
#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

#define F first
#define S second

typedef pair<li, li> PI;
map<PI, li> cnt;

int main(void)
{
	li n;
	cin>>n;
	string s;
	cin>>s;
	li res=0;
	rep(i,s.size() - 2) {
		if(s.substr(i,3)=="ABC"){
			res++;
		}
	}
	cout<<res<<endl;


	return 0;
}