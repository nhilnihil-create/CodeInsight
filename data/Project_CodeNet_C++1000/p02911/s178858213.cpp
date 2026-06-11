#include<bits/stdc++.h>
using namespace std;

#define ASC(vec) vec.begin(), vec.end() 
#define DESC(vec) vec.rbegin(), vec.rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, vec.size()) cin>>vec[i]; 
#define ANS(s) cout << s << endl;
#define inc(a, b) cin >> a >> b;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> tamesi (n,0);
	vector<int> tamesi1 (q);
	In(tamesi1);

	for(auto v : tamesi1){
			tamesi[v-1] = tamesi[v-1]+1;
 	}

	for(auto v: tamesi){
			if(k-q+v>=1) cout<<"Yes"<<"\n";
			else cout<<"No"<<"\n";
	}
	return 0;
}
