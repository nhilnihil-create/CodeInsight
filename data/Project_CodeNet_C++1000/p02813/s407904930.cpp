#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n),b(n),c(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i] = a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	sort(c.begin(),c.end());

	int apos,bpos,cnt = 0;

	do{
		if(a == c) apos = cnt;
		if(b == c) bpos = cnt;
		cnt++;
	}while(next_permutation(c.begin(), c.end()));

	cout<<abs(apos-bpos)<<endl;	
}