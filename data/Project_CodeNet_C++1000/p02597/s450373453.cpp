#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define forv(v) for(vector <int> :: iterator iter=v.begin();iter!=v.end();++iter)
#define form(v) for(map<int,int> :: iterator iter=v.begin();iter!=v.end();++iter)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define rev(a,n) reverse(a,a+n)
#define pql priority_queue<ll>
#define ort1(a) sort(a+1,a+n+1)
#define ort(a) sort(a,a+n)
#define LL long long
#define N 500005
using namespace std;
int n,res;
string s;
int main(){
	cin>>n>>s;
	queue<int> pos;
	rep(i,0,n) {
		if(s[i]=='W') pos.push(i);
	}
	ford(i,n-1,0){
		if(s[i]=='W') continue;
		if(pos.empty()) break;
		int p=pos.front();
		pos.pop();
		if(p>i) break;
		else {
			swap(s[p],s[i]);
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}