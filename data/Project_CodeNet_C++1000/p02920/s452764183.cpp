#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

void finish(){
	show("No");
	exit(0);
}

int32_t main(){
    fast_io;
    int n;
    cin>>n;
    n = 1<<n;
    multiset<int>s;
    for (int i = 0; i < n; ++i)
    {
    	int x;
    	cin>>x;
    	s.insert(x);
    }
    vi v;
    v.emplace_back(*s.rbegin());
    s.erase(s.find(v.back()));
    while(!s.empty()){
    	sort(v.rbegin(), v.rend());
    	vi temp;
    	for(const auto &it:v){
    		if(it <= *(s.begin())) finish();
    		auto j = s.lower_bound(it);
    		j--;
    		temp.emplace_back(*j);
    		s.erase(j);
    	}
    	for(const auto &it:temp) v.emplace_back(it);
    }
	
	show("Yes");
    return 0;
}