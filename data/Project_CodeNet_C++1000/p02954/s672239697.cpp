#include<bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define rep1(i,n)for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=(int)(n)-1;0<=i;i--)
#define rrep1(i,n) for(int i=(int)(n);1<=i;i--)

#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(obj) (obj).begin(),(obj).end() 

#define pcount __builtin_popcount
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define endl "\n"

template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

typedef long long lint;

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int l=LEN(s);
	vector<int>n(l,0);
	vector<int>L;
	vector<int>R;
	rep(i,l){
		if(s[i]=='L')L.push_back(i);
		else R.push_back(i*-1);
	}
	sort(all(R));
	rep(i,l){
		if(s[i]=='R'){
			auto it=lower_bound(all(L),i);
			int tmp=*it;
			if((tmp-i)%2==0)n[tmp]++;
			else n[tmp-1]++;
		}
		else {
			auto it=lower_bound(all(R),i*-1);
			int tmp=(*it)*-1;
			if((i-tmp)%2==0)n[tmp]++;
			else n[tmp+1]++;
		}
	}
	rep(i,l)cout<<n[i]<<" ";
	cout<<endl;
}