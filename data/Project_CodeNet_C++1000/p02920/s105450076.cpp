#include <bits/stdc++.h>
using namespace std;
//F1

int mypow(int mpx,int mpn){
	if(mpn==0) return 1;
	if(mpn%2==0) return mypow((mpx*mpx),mpn/2);
	else return (mpx*mypow(mpx,mpn-1));
} 

int main() {
	// your code goes here
	int n,i,j,ca=0,cb=0;
	long long s[300000],max=0,ma,mb,sm=1;
	vector<long long> nod;
	priority_queue<long long> a,b,c;
	cin >> n;
	for(i=0;i<mypow(2,n);i++){
		cin >> s[i];
		if(max<s[i]) max=s[i];
		a.push(s[i]);
	}
	sort(s,s+mypow(2,n));
	nod.push_back(s[0]);
	for(i=1;i<mypow(2,n);i++){
		if(s[i-1]!=s[i]) nod.push_back(s[i]);
	}
	for(i=0;i<n;i++){
		if(s[mypow(2,n)-mypow(2,i)]<=nod[n-i-1]){
			cout << "No" << endl;
			return 0;
		}
	}
	s[0]=1;
	for(i=1;i<=n;i++){
		for(j=mypow(2,i-1);j<mypow(2,i);j++){
			s[j]=s[j-mypow(2,i-1)]+1;
		}
	}
	for(i=0;i<mypow(2,n);i++){
		b.push(s[i]);
	}
	ma=a.top(); mb=b.top();
	a.pop(); b.pop();
	for(i=1;i<mypow(2,n);i++){
		if(ma>a.top()) ca++;
		if(mb>b.top()) cb++;
		if(cb>ca){
			cout << "No" << endl;
			return 0;
		}
		ma=a.top(); mb=b.top();
		a.pop(); b.pop();
	}
	cout << "Yes" << endl;
	return 0;
}