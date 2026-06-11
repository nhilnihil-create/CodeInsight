//raja1999

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
//#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


//std::ios::sync_with_stdio(false);

int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,m,i,x,k,fl=0;
	cin>>n>>m;
	if(n%2==0){
		fl=1;
		n--;
	}
	if(n%4==1){
		x=1;
		k=n/4;
		fd(i,k,1){
			if(m==0){
				break;
			}
			m--;
			cout<<i<<" "<<i+x<<endl;
			x+=2;
		}
		x=2;
		fd(i,3*k,2*k+1){
			if(m==0){
				break;
			}
			m--;
			cout<<i<<" "<<i+x<<endl;
			x+=2;
		}
	}
	else{
		x=1;
		k=n/4;
		fd(i,k,1){
			if(m==0){
				break;
			}
			m--;
			cout<<i<<" "<<i+x<<endl;
			x+=2;
		}
		if(m!=0){
			m--;
			cout<<2*k+1<<" "<<4*k+3+fl<<endl;
		}

		x=2;
		fd(i,2*k+1+k,2*k+2){
			if(m==0){
				break;
			}
			m--;
			cout<<i<<" "<<i+x<<endl;
			x+=2;
		}
		
	}
	return 0;
} 
