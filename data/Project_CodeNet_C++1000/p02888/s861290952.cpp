#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<utility>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
int cnt[1005];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
template<typename T> void debug(T x)
{
    cout<<"value="<<x<<endl;
    return;
}
signed main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	int n=read();
	for(int i=1;i<=n;i++){
        int x=read();
        cnt[x]++;
	}
	vector<pair<int,int> > a;
	for(int i=1;i<=1000;i++){
        if(cnt[i]>0){
            pair<int,int> tmp=make_pair(i,cnt[i]);
            a.push_back(tmp);
        }
	}
	ll ans=0;
	int len=a.size();
	for(int i=0;i<=len-3;i++) for(int j=i+1;j<=len-2;j++) for(int k=j+1;k<=len-1;k++){
        if(a[i].first+a[j].first>a[k].first && a[i].first+a[k].first>a[j].first && a[j].first+a[k].first>a[i].first){
            ans+=(a[i].second*a[j].second*a[k].second);
        }

	}
	for(int i=0;i<=len-1;i++){
        if(a[i].second>=3){
            ll xx=(ll)a[i].second;
            ans+=(xx)*(xx-1)*(xx-2)/6;
        }
	}
	for(int i=0;i<=len-1;i++){
        for(int j=0;j<=len-1;j++){
            if(j==i) continue;
            if(2*a[i].first>a[j].first && a[i].second>=2) ans+=(a[i].second)*(a[i].second-1)*(a[j].second)/2;
        }
	}
	cout<<ans<<endl;
	return 0;
}
