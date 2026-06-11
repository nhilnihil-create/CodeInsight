#include<bits/stdc++.h>
using namespace std;
multiset<int,greater<int> > S,T;
int n,tmp[1<<18];
int main(){
	scanf("%d",&n);
	for(int i=0,x;i<(1<<n);++i){
		scanf("%d",&x);
		S.insert(x);
	}
	T.insert(*S.begin());
	S.erase(S.begin());
	for(int i=0,t=0;i<n;++i){
		auto itr=S.begin();
		for(int x: T){
			while(itr!=S.end()&&*itr==x)++itr;
			if(itr==S.end())
				puts("No"),exit(0);
			tmp[t++]=*itr;
			itr=S.erase(itr);
		}
		if(i!=n-1)T.insert(tmp,tmp+t),t=0;
	}
	puts("Yes");
	return 0;
}
