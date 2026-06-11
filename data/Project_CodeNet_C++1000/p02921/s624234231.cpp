#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int a[100005], n, m;

int main(){
	int i, j=0;
	string s, t;
	cin >> s >> t;
	for(i=0;i<3;i++)if(s[i]==t[i])j++;
	cout << j;
}
