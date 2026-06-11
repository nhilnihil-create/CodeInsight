#include<bits/stdc++.h>
using namespace std;

#define ASC(vec) vec.begin(), vec.end() 
#define DESC(vec) vec.rbegin(), vec.rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, n) cin>>vec[i]; 
#define ANS(s) cout << s << endl;
#define inc(a, b) cin >> a >> b;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	long long int kotae = 0;
	cin>>n>>m;

	priority_queue<int> tamesi;

	rep(i,n){
			int mosi;
			cin>>mosi;
			tamesi.push(mosi);
	}

	rep(i,m){
		int kon;
		kon = tamesi.top();	
		tamesi.pop();
		tamesi.push(kon/2);
	}

	rep(i,n){
		kotae += tamesi.top();
		tamesi.pop();
	}

	cout<<kotae<<endl;
	return 0;
}
