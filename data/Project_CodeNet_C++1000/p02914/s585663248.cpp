/* Author: Dhruv Rastogi */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int> 
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second
const long double PI = acos(-1.0);

int a[100005];
int used[100005];
int cnt[65];
bool good[65];
int basis[65];
void solve(){  
	int n;
	cin>>n;
	int ans=0;
	rep(i,0,n){
		cin>>a[i];
		ans^=a[i];
		repd(j,60,0){
			if((a[i]>>j)&1){
				cnt[j]++;
			}
		}
	}  
	int max_and = 0;
	rep(i,0,61){
		if(cnt[i] && cnt[i]%2==0){
			good[i]=1;
		}
	}
	//compute max_and
	rep(i,0,n){
		int cur=a[i];
		repd(j,60,0){
			if(!good[j])
				continue;
			if((cur>>j)&1){
				if(basis[j]==0){
					basis[j]=cur;
					break;
				}
				else cur^=basis[j];
			}
		}
	}
	int cur=0;
	repd(j,60,0){
		if(good[j]){
			if((cur>>j)&1){
				max_and+=(1LL<<j);
			}
			else{
				if(basis[j]){
					cur^=basis[j];
					max_and+=(1LL<<j);
				}
			}
		}
	}
	cout << ans + 2*max_and<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}