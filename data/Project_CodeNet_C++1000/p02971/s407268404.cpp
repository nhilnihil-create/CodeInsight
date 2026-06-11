#include <bits/stdc++.h>
   
#define pb push_back
#define ll long long
#define f first
#define s second
#define ld long double
#define fa fflush(stdout); 

using namespace std;
void data() {
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
} 
const int N = 5e5 + 100;
const ll mod = 1e9 + 7;
 
int main ()
{
	data();                          
	int n;
	cin >> n;
	int a[n + 1];
	int mx = 0;
	int kol = 0;
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		s.insert(a[i]);
	}
	s.erase(*s.rbegin());
	int ans2;
	if (s.size() > 0)
	{
		ans2 = *s.rbegin();
	}
	for (int i = 1; i <= n; i++)
	{
		if (mx == a[i])
		{
			kol++;
		}
	}
	for (int i = 1; i <= n; i++)
	{                                
		if (a[i] != mx)
		{
			cout << mx << '\n';
			continue;
		}
		if (kol > 1)
		{
			cout << mx << '\n';
			continue;
		}
		cout << ans2 << '\n';
	}
	
}     
//JUDGE_ID: 295965SY
//Tis I