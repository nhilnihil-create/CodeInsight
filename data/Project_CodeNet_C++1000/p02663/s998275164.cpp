#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}



int main(){
	int h1,m1,h2,m2,s,t,K;
	read(h1),read(m1);
	s=h1*60+m1;
	read(h2),read(m2);
	t=h2*60+m2;
	read(K);
	cout<<max(0,t-s-K)<<endl;
	return 0;
}
