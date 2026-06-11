
// Problem : D - Road to Millionaire
// Contest : AtCoder - M-SOLUTIONS Programming Contest 2020
// URL : https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
#define 	ll		    long long
#define 	rep(i,a,n)  for(int i=a;i<n;i++)
#define 	MOD 		1000000007
#define 	vp 			vector<pair<int,int> >
#define 	ff 			first
#define 	ss 			second
#define 	pb 			push_back
#define 	all(x) 		(x.begin(),x.end())
#define 	dg(x)		cerr<<"--- x = "<<x<<"\n"
#define 	endl		"\n"


using namespace std;
const int N = 1e5;
ll ar[N];

void solve(){
	int n; cin >> n;
	ll money = 1000;
	rep(i,1,n+1)
		cin >> ar[i];
		
	rep(i,2,n+1){
		if(ar[i] > ar[i-1]){
				ll q =  money / ar[i-1];
				money =  money % ar[i-1];
				money += (ar[i] * q);
		}
	}
	cout << money ;
	
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
