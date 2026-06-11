#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;



signed main(){
	int n;
	cin>>n;
	int bit=1<<n;
	vector<int>s(bit);
	rep(i,bit)cin>>s[i];
	sort(s.begin(),s.end());
	vector<int>a;
	a.pb(s.back());
	s.back()=-1;//使用済みのものは-1に
	rep(i,n){
		vector<int>p=a;//pはi秒で生成するスライムの親しか含まない
		sort(p.begin(),p.end());//大きいものから貪欲に
		int id=bit-1;
		while(p.size()>0&&id>=0){
			if(s[id]==-1){
				--id;//過去にやった操作はカット
				continue;
			}
			if(s[id]<p.back()){//大きいものから貪欲に使う
				a.pb(s[id]);//集合そのものに含む
				p.pop_back();//i秒での役目を終える
				s[id]=-1;//使用したので
			}
			--id;//親より大きくてもs全体を見たいので進める
		}
		if(p.size()>0){//全ての親を使わないといけないので残っているということは失敗
			cout<<"No\n";
			return 0;
		}

	}
	cout<<"Yes\n";
	return 0;
}