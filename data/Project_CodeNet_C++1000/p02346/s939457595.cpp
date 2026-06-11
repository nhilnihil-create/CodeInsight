#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

template<class V> class BIT {
private:
	int n; vector<V> bit;
public:
	void add(int i,V x){ i++; while(i <= n) bit[i] += x, i += i & -i;}
	V sum(int i){i++; V s = 0; while(i>0) s += bit[i], i -= i & -i; return s;}
	BIT(int sz){ n = sz + 1, bit.resize(n,0);} //?????????????????????0?????´???
	BIT(vector<V> v){n = (int)v.size()+1; bit.resize(n); rep(i,n) add(i,v[i]);}
	void print(){ rep(i,n-1)cout<<sum(i)-sum(i-1)<< " ";cout<<endl;}
	void print_sum(){ rep(i,n)cout<<sum(i-1)<<" ";cout<<endl;}	//-1????????????
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    BIT<int> bt(n);
    rep(i,q){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0){
            bt.add(b-1,c);
        }else{
            cout << bt.sum(c-1) - bt.sum(b-2) << endl;
        }
    }
    return 0;
}