#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;

template<class T>void read(T &x){
    T s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    x = s*w;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
int N;
set<string> st;
void solve(){
	
}	
int main(){
	// debug;
	ios;

	cin>>N;
	for(int i = 1;i<=N;i++) {
		string s;cin>>s;
		st.insert(s);
	}
	cout<<st.size()<<'\n';
	return 0;
}
