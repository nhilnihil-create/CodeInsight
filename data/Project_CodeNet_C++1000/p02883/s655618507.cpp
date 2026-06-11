//============================================================================
//  Falling Down is an accident, Staying Down is a Choice.
// Author      : Murad
// Online Judge: Codeforces.cpp & Atcoder.cpp
// Description : Problem name
//============================================================================
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<utility>
using namespace std;
typedef                                    long long LL;
#define                                    pi 3.1415926536
#define                                    forn(i,a,b)for(int i=a;i<b;i++)
#define                                    ULL unsigned long long
#define                                    MP make_pair
#define                                    ff first
#define                                    ss second
#define                                    endl '\n'
#define                                    INF LL(1e9);
#define                                    _INF INT32_MIN
#define                                    pq priority_queue
#define                                    MM multimap
#define                                    PB push_back
#define                                    EMPP emplace_back
#define                                    vii vector<int>
#define                                    vll vector<LL>
#define                                    ipair pair<int,int>
#define                                    lpair pair<LL,LL>
#define                                    clr(v, d) memset(v, d, sizeof(v))
#define                                    El3zba ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define                                    modd 1000000007
#define                                    sf1(v) scanf("%I64d",&v);
#define                                    sf2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define                                    sf3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
                                           //std::transform(s1.begin(), s1.end(), s1.begin(),::tolower);
                                           char  alphz[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
float Euclidean(LL x1, LL x2, LL y1, LL y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
LL GCD(LL a, LL b) {
	return !b ? a : GCD(b, a % b);
}
LL LCM(LL a, LL b) {
	return (a*b) / GCD(a, b);
}
void PrimeFactor(LL n)
{
	while (n % 2 == 0) {
		//printf("%d ", 2);
//		aa.insert(2);
		n /= 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n%i == 0) {
			//printf("%d ", i);
			//aa.insert(i);
			n /= i;
		}
	}
	if (n > 2) {
		//printf("%d ", n);
	//	aa.insert(n);
	};
}
bool Is_Square(LL x) {
	LL l = 0, r = x;
	while (l <= r) {
		LL mid = l + (r - l) / 2;
		if (mid*mid == x)return true;
		if (mid*mid > x)r = mid - 1;
		else l = mid + 1;
	}
	return false;
}
LL Power(LL x, LL y)
{
	LL temp;
	if (y == 0)return 1;
	temp = Power(x, y / 2);
	if (y % 2 == 0)
		return (temp*temp);
	else return (x*temp*temp);
}
bool Is_Prime(int x) {
	if (x == 2)return 1;
	else if (x % 2 == 0 || x < 2)return 0;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return 0;
	return 1;
}
bool Is_Palin(string s)
{
	int i = 0, j = (int)s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])return 0;
		i++, j--;
	}
	return 1;
}
int main()
{
	El3zba;
	/***  بسم الله الرحمن الرحيم   ***/
	LL n, k;
	cin >> n >> k;
	vii mo(n), riv(n);
	for (int i = 0; i < n; i++)
		cin >> mo[i];
	for (int i = 0; i < n; i++) 
		cin >> riv[i];
	sort(mo.begin(), mo.end());
	sort(riv.begin(), riv.end(),greater<int>());
	LL hig = 1e12+50;
	LL low = -1;
	while (low+1<hig) {
		LL cnt = 0;
		LL mid = low+(hig - low) / 2;
		for (int i = 0; i < n; i++)
		{
			LL ned = mid / riv[i];
			if (ned < mo[i])
				cnt += mo[i] - ned;
		}
		if (cnt <= k)
			hig = mid;
		else
			low =mid ;
	}
	cout << hig<< endl;
	return 0;
}

