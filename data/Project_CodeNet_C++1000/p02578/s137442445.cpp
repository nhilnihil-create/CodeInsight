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
	Long n; cin>>n;
    Long tam[n];
    Rep(i,0,n){
        cin>>tam[i];
    }
    Long total = 0;
    Rep(i,1,n){
        if(tam[i-1]>tam[i]){
            total += tam[i-1]-tam[i];
            tam[i] = tam[i-1];
        }else{
            continue;
        }
    }
    cout<<total;
	return 0;
}