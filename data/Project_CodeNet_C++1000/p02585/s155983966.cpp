#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cinttypes>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<stack>


#define FSCNd64 "%" SCNd64
#define FPRId64 "%" PRId64

using namespace std;

using ll=long long;
using vb=vector<bool>;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795

template<typename X>
bool max_u(X&m, X v)
{
	if(m<v)
	{
		m=v;
		return true;
	}
	return false;
}


template<typename X>
bool min_u(X&m, X v)
{
	if(m>v)
	{
		m=v;
		return true;
	}
	return false;
}


struct loop_t
{
	vll c_sum;
	vll c_max;
	vll c_rmax;

void dump(void)
{
	int n=c_sum.size();
	for(int i=0;i<n;i++)
	{
		cout << "(" << c_sum[i] << "," << c_max[i] << "," << c_rmax[i] << ")";
	}
	cout << "\n";
}
};


template <typename X>
struct btmax_t
{
	vector<X> t;
	int base;
	btmax_t(int n)
	{
		for(base=1;base<n;base*=2)
			;
		t.resize(base*2);
	}
	btmax_t(int n, X x)
	{
		for(base=1;base<n;base*=2)
			;
		t.resize(base*2, x);
	}
	void seti(int idx)
	{
		if(idx<=0) return;

		if(t[idx*2]<t[idx*2+1]) t[idx]=t[idx*2+1];
		else t[idx]=t[idx*2];

		seti(idx/2);
	}
	void set(int idx, const X&v)
	{
		int y=idx+base;
		t[y]=v;
		seti(y/2);
	}
	X get(void)
	{
		return t[1];
	}
};


template<typename X>
void dump(vector<X>&v)
{
	for(auto&m:v) cout << m << " ";
	cout << "\n";
}


struct solve
{
	solve(){}
	ll operator()() {
		return 0;
	}
};

int main(void)
{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);

	for(;;)
	{
		int n, k;
		cin >> n >> k;
		if(cin.fail()) break;
		vi p(n+1);
		vll c(n+1);
		for(int i=1;i<=n;i++) cin >> p[i];
		for(int i=1;i<=n;i++) cin >> c[i];

		ll ans=c[1];
		vb is_passed(n+1, false);

		for(int i=1;i<=n;i++)
		{
			if(is_passed[i]) continue;
			int cp=i;
			int g_num=1;
			for(int j=0;j<=n;j++)
			{
				if(is_passed[cp])
				{
					g_num=j;
					break;
				}
				is_passed[cp]=true;
				cp=p[cp];
			}

			vll sum={c[cp]};
			ll sum_min=sum.back();
			for(int j=1;j<g_num*3;j++)
			{
				cp=p[cp];
				sum.push_back(sum.back()+c[cp]);
				min_u(sum_min, sum.back());
			}
//dump(sum);
			int loop_num=max(0, (int)k/g_num-1);
			ll ans_add=sum[g_num-1]*loop_num;
			if(ans_add<0) ans_add=0;

			int chk_size=k-loop_num*g_num;
			btmax_t<ll> t(chk_size, sum_min);
			for(int j=0;j<chk_size;j++)
			{
				t.set(j, sum[j]);
			}
			for(int j=0;j<g_num;j++)
			{
				t.set(j%chk_size, sum[chk_size+j]);
				max_u(ans, t.get()-sum[j]+ans_add);
			}
//printf("loop_num=%d  g_num=%d  ans_add=%lld\n", loop_num, g_num, ans_add);
		}

		cout << ans << "\n";
	}
	return 0;
}
