#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e5;
LL enter_count[N+1];
LL exit_count[N+1];
LL exit_len[N+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h1, m1, h2, m2, k; cin >> h1 >> m1 >> h2 >> m2 >> k;
	cout<<(60*(h2-h1)+(m2-m1)-k)<<endl;

	cout<<flush;
	return 0;
}