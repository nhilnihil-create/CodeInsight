#include<bits/stdc++.h>
using namespace std;


// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3") 
// #pragma GCC optimization ("unroll-loops")
 
#define ll  long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;
 
#define MD          1000000007
#define M           1000011
#define N 			20
long long  md=MD;

int solve(){
	int n,i,j,k,m;
	cin>>n;
	multiset<int> st;
	for(i=0;i<(1<<n);++i){
		int x;
		cin>>x;
		st.insert(-x);
	}
	n=1<<n;
	int flg=1;
	int mx=-*st.begin();
	st.erase(st.begin());
	multiset<int> used;
	vector<int> v;
	v.pb(-mx);
	while(st.size()){
		int k=v.size();
		for(i=0;i<k;++i){
			int ma=v[i];
			if(st.upper_bound(ma)==st.end()){
				cout<<"No\n";die();
			}
			int p=*st.upper_bound(ma);
			st.erase(st.find(p));
			v.pb(p);
		}
		sort(all(v));

	}
	cout<<"Yes\n";die();


}


int main(){

 
     
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    // cin>>t;

    while(t--){
    	solve();
    }
    die();



    

}

