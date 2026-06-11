#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mp make_pair
#define F first
#define S second
#define B begin
#define E end
#define PB push_back
#define endl "\n"

#define FORS(i, j, k, step) for (int i=j; i<k; i+=step)
#define FOR(i, j, k) for (int i=j; i<k; i++) 
#define RFORS(i, j, k, step) for (int i=j; i>=k; i-=step)
#define RFOR(i, j, k, step) for(int i=j; i>=k; i--)
#define REP(i, k) for(int i = (0); i < (k); i++ )
#define RREP(i, k) for(int i = j; i >= (k); i-- )

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
void read_vec(vector<T>& v, int n){
    T tmp;
    REP(i, n){
        cin>>tmp;
        v.push_back(tmp);
    }
}

void solve(){
	int d, t, s;
	cin>>d>>t>>s;
	if((float)d/s <= (float)t){
		cout<<"Yes"<<endl;
	}	
	else cout<<"No"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC =1;
    //cin>>TC;

    REP(tc, TC){
    	solve();
    }

}