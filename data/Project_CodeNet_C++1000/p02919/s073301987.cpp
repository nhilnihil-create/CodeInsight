#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
const int maxn=2e5+5;

set<int>s;

vi help(int x){
	auto it = s.find(x);
	vi v;
	v.emplace_back(*it);
	for (int i = 0; i < 2; ++i)
	{
		if(it == s.begin()) break;
		it--;
		v.emplace_back(*it);
	}
	it = s.find(x);
	for (int i = 0; i < 2; ++i)
	{
		it++;
		if(it == s.end()) break;
		v.emplace_back(*it);
	}
	sort(v.begin(), v.end());
	return v;
}

int32_t main(){
    fast_io;
    int n;
    cin>>n;
    int f[n+1],a[n+1];
    fo(i,1,n){
    	cin>>a[i];
    	f[a[i]] = i;
    	s.insert(i);
    }
    int ans = 0;
    fo(i,1,n){
    	vi v = help(f[i]);
    	int id = 0;
    	for (int j = 0; j < v.size(); ++j)
    	{
    		if(v[j] == f[i]) {
    			id = j;
    			break;
    		}
    	}
    	if(id){
    		int val = 1;
    		int l = 0;
    		if(id-1 > 0) l = v[id-2];
    		val *= (v[id-1] - l);
    		int r = n+1;
    		if(id+1 < v.size()) r = v[id+1];
    		val *= (r - v[id]);
    		ans += val*i;
    	}
    	if(id+1 < v.size()){
    		int val = 1;
    		int l = 0;
    		if(id-1 >= 0) l = v[id-1];
    		val *= (v[id]-l);
    		int r = n+1;
    		if(id+2 < v.size()) r = v[id+2];
    		val *= (r - v[id+1]);
    		ans += val*i;
    	}
    	s.erase(f[i]);
    }
    show(ans);
    return 0;
}