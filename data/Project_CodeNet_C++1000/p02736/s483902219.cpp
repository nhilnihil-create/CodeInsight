#include <bits/stdc++.h>
 
#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif
 
using namespace std;

int nCr(int n, int r)
{
	if(n<r) return 0;
	if(r==0 || n==r) return 1;
	return (n%2>=r%2)*nCr(n/2,r/2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, ans=0;
	bool chk=false;
	string s;
	cin>>N>>s;
	for(auto &c: s) if(--c=='1') chk=true;
	for(int i=0;i<N;i++) {
		if(chk) {
			if((s[i]-'0')&1) ans^=nCr(N-1,i);
		}
		else if(s[i]-'0') ans^=nCr(N-1,i);
	}
	cout<<(chk ? ans:2*ans)<<'\n';
	return 0;
}