#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

// Most important thing in CP - Have Fun :)

bool possible(vi &arr,int mid,int k){
    int count = 0;
    rep(i,0,sz(arr)){
        if (arr[i]<=mid)continue;
        else count+= (arr[i])/mid;
        if (count>k)return false;
    }
    return true;
}

void solve(){
	//write here
   //WRWWRWRR -- > RRWWRWRW --> RRRWWRWWW
    int n,k;
    cin>>n>>k;
    vi arr(n);
    rep(i,0,n)cin>>arr[i];
    int start = 1,end = 1e9+1;
    int ans;
    while (start<=end){
        int mid  = (start+end)/2;
        if (possible(arr,mid,k)){
            ans = mid;
            end = mid-1;
        }
        else start  = mid+1;
    }
    cout<<ans<<endl;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	
		solve();
	return 0;
}