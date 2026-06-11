#include<bits/stdc++.h>
#define DBG(x) cerr << #x << “ = ” << (x) << endl
#define Rep(i,a,b) for (int i = a, to = b; i < to; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

typedef long long Long;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string n; cin>>n;
    Long sum = 0;
    Rep(i,0,n.size()){
        sum+=n[i]-'0';
    }
    if(sum%9==0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
	return 0;
}