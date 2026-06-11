#include<iostream>
#include<vector>
#include<functional>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
//=なし
void recursive_comb(vector<int>&co, int s, int rest,vector<int>a,vector<int>b,vector<int>c,vector<int>d,int* max) {
	if (rest == 0) {
		//do st
		int sum = 0;
		rep(i,a.size()){
			if(co[b[i]-1]-co[a[i]-1]==c[i]){
				sum += d[i];
			}
		}
		if(*max<sum)*max=sum;
		} else {
		if (s < 0) return;
		recursive_comb(co, s - 1, rest,a,b,c,d,max);
		co[rest - 1] = s;
		recursive_comb(co, s - 1, rest - 1,a,b,c,d,max);
	}
}
//=あり
void recursive_comb2(vector<int>&co, int s, int rest,vector<int>a,vector<int>b,vector<int>c,vector<int>d,int* max) {
	if (rest == 0) {
		//do st
		int sum = 0;
		rep(i,a.size()){
			if(co[b[i]-1]-co[a[i]-1]==c[i]){
				sum += d[i];
			}
		}
		if(*max<sum)*max=sum;
		//rep(i,co.size())cout<<co[i]<<" ";
		//cout<<endl;
		} else {
		if (s < 0) return;
		recursive_comb2(co, s - 1, rest,a,b,c,d,max);
		co[rest - 1] = s;
		recursive_comb2(co, s, rest - 1,a,b,c,d,max);
	}
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k,vector<int>a,vector<int>b,vector<int>c,vector<int>d,int*max) {
	vector<int> co(k);
	recursive_comb2(co, n - 1, k,a,b,c,d,max);
}
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<int>a(q),b(q),c(q),d(q);
	rep(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];
	int max = 0;
	foreach_comb(m,n,a,b,c,d,&max);
	cout<<max<<endl;
	return 0;
}