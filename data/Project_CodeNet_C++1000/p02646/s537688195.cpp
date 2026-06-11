#include<bits/stdc++.h>
#define N 300050
#define M 200
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
#define MOD mod
using namespace std;
int a,v,b,w,t;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin>>a>>v>>b>>w>>t;
    if(a>b)swap(a,b);
    a += v*t;
    b += w*t;
    if(a>=b){
        cout<<"YES";
    }
    else cout<<"NO";
  	return 0;
}

