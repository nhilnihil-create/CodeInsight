#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int mn=1<<19;
vector<int> a,b;
multiset<int> s;

int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);++i) {scanf("%d",&x);s.insert(x);}
	a.pb(*--s.end());s.erase(--s.end());
	while(n--) {
		for(int i=0;i<a.size();++i) {
			multiset<int>::iterator it=s.lower_bound(a[i]);
			if(it==s.begin()) {
				puts("No");
				return 0;
			}
			it--;b.pb(*it);s.erase(it);
		}
		for(int i=0;i<b.size();++i) a.pb(b[i]);
		b.clear();
	}
	puts("Yes");
}