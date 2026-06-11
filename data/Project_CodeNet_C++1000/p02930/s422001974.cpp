/*
 * じょえチャンネル
 * 高評価・チャンネル登録よろしくおねがいします！
 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
signed main(){
	cin>>N;
	rep(i,N-1){
		for(int j=i+1;j<N;j++){
			rep(k,10){
				if((i>>k&1)!=(j>>k&1)){
					cout<<k+1<<" ";
					break;
				}
			}
		}
		cout<<endl;
	}
}
