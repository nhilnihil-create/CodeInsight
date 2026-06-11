#include<bits/stdc++.h>
using namespace std;
int a[100005],Cnt;
map<int,int> mp;
int main(){
//	freopen("test_15.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],Cnt+=(a[i]==a[i-1]);
	if(Cnt==n) return puts("Yes"),0;
	if(n%3!=0) puts("No");
	else{
		int cnt=0;
		for(int i=1;i<=n;++i)
			mp[a[i]]++;
		int A=0,B=0,C=0;
		for(int i=1;i<=n;++i)
			if(mp[a[i]]==n/3){
				cnt++,mp[a[i]]--;
				if(cnt==1) A=a[i];
				if(cnt==2) B=a[i];
				if(cnt==3) C=a[i];
			} 
	//	cout<<cnt<<" "<<A<<" "<<B<<" "<<C<<endl;
		if(cnt==1 && A==0) return puts("Yes"),0;
		if(cnt==3 && (A^B)==C) puts("Yes");
		else puts("No");
	}
	return 0;
}