//#include <bits/stdc++.h>
#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map> 
#include<cmath>
#include<math.h>
#include<set>
#include<vector>
using namespace std;
	 
#define PI acos(-1.0)
#define CIR(i, l, u) for(int i = l; i < u; ++i)
#define cir(i, u, l) for(int i = u; i > l; --i)
#define p(x) cout << x << endl
#define pd(x) cout << "*" << x << endl
#define py cout << "YES" << endl
#define pn cout << "NO" << endl 
#define INI(n, i) memset(n, i, sizeof(n))
#define MAX(a, b) a = a > b ? a : b
#define MIN(a, b) a = a < b ? a : b
//#define ll __int64
#define ll long long

const ll inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

//typedef long long ll;
const ll mod = 1e9 + 7;
/*以前放进来的，如果有使用，并非排位期间所查。 
有cf交题的记录可证*/ 

//struct cmp2
//{
//    bool operator () (const ll a,const ll b)
//    {
//        return a>b;//????
//    }
//};
//
//ll gcd(ll m,ll n)
//{
//    ll y;  
//    y=m%n;
//    while(y!=0)
//    {
//        m=n;
//        n=y;
//        y=m%n;
//    }
//    return n;
//}
//
//ll lcm(ll a, ll b)
//{
//	return a*b / gcd(a,b);
//}
//
////欧拉筛
//bool isPrime[400005];
////isPrime[i] == 1表示：i是素数
//int Prime[400005], cnt = 0;
////Prime存质数
//
//void GetPrime(int n)//筛到n
//{
//	memset(isPrime, 1, sizeof(isPrime));
//	//以"每个数都是素数"为初始状态，逐个删去
//	isPrime[1] = 0;//1不是素数
//	
//	for(ll i = 2; i <= n; i++)
//	{
//		if(isPrime[i])//没筛掉 
//			Prime[++cnt] = i; //i成为下一个素数
//			
//		for(ll j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) 
//		{
//        	//从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
//            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
//			isPrime[ i*Prime[j] ] = 0;
//            
//			if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
//				break; //重要步骤。见原理
//		}
//	}
//}
//
//void decompose(int n)
//{
//	int pos = 1, pr = Prime[pos];
//	while(pr * pr <= n)
//	{
//		int ct = 0;
//		while(0 == n % pr)
//		{
//			++ct;
//			n /= pr;
//		}
//		
//		if(ct)
//		{
//			++vis[pos];
//			sum[pos].push_back(ct);
//		}
//		
//		pr = Prime[++pos];
//	}
//	
//	if(n > 1)
//	{
//		pos = pr_to_pos[n];
//		sum[pos].push_back(1); ++vis[pos];
//	}
//}
//
//struct node{
//	int cccol, dis, pos;
//	
//friend  bool operator<(const node &a,const node &b) {
////        if(a.dis == b.dis) return a.dis > b.l;
//		return a.dis > b.dis;
//    }
//    friend  bool operator>(const node &a,const node &b) {
////        if(a.lg == b.lg) return a.l < b.l;
//		return a.dis < b.dis;
//}
//};
//
//priority_queue<node> V;
//
//double ksm(double a, int m)
//{
//	double re = 1.0;
//	while(m)
//	{
//		if(m & 1) re*=a;
//		a = a*a;
//		m /=2;
//	}
//	
//	return re;
//}

template<class T>void read(T &x)
{
x=0;int f=0;char ch=getchar();
while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
x=f?-x:x;
return;
}


//int main()
//{
//	int n; cin >> n;
//	int num[n + 5]; INI(num, 0);
//	CIR(i, 0, n) cin >> num[i];
//	int ver = 0, jg = 0, up = n - 1, now = 0, l = 0, r = 0;
//	CIR(i, 0, up)
//	{		
//		if(now)
//		{
//			if(num[i] < num[i + 1])
//			{
//				if(num[l] < num[i + 1] && ((l > 0 && num[r] > num[l - 1]) || l == 0)) now = 0;
//				else
//				{
//					pd(i);
//					jg = 1;
//					break;
//				}
//			}
//			else ++r;
//		}
//		else
//		{
//			if(num[i] >= num[i + 1])
//			{
//				now = 1;
//				++ver;
//				if(ver == 2)
//				{
//					jg = 1;
//					break;
//				}
//				l = i;
//				r = i + 1;
//			}
//		}
//	}
//	
//	if(jg) p("impossible");
//	else p(l + 1 << " " << r + 1);	
//	
//	
//	
//	return 0;
//} 

int main()
{
	int n, m, sum; cin >> n >> m >> sum;
	CIR(i, 0, n)
	{
		if(m)
		{
			if(i < n - 1) cout << sum << " ";
			else cout << sum;
			--m;
		}
		else
		{
			int tmp = 0;
			if(sum == 1 || sum == 2) tmp = 1e9;
			else tmp = sum - 1;
			
			if(i < n - 1) cout << tmp << " ";
			else cout << tmp;
		}
	}
	cout<<endl;
}