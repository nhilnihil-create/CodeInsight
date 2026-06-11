#include<bits/stdc++.h>
using namespace std;
const int maxn=3+1e5;
const int inf = 0x3f3f3f3f;

typedef pair<int,int> II;
typedef long long ll;

int D[maxn], R[maxn], L[maxn];
int top;
int n, a[maxn];
long long ans;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	top = 0;
  D[0] = 0;
	for (int i = 1; i <= n; ++i){
    while (top > 0 && a[D[top]] < a[i]) --top;
    L[i] = D[top] + 1;
    --L[i];
    D[++top] = i;
	}
	top = 0;
	D[0] = n+1;
	for (int i = n; i >= 1; --i) {
    while (top > 0 && a[D[top]] < a[i]) --top;
    R[i] = D[top] - 1;
    ++R[i];
    D[++top] = i;
	}

//	for(int i=0;i<n;++i) cout<<L[i+1]<< " "<<R[i+1]<<'\n';

	for (int i = 1; i <= n; ++i) {
    int l = L[i], r = R[i];
    int cnt = 0;
    if (l > 0) {
      --l;
      while (a[l] < a[i] && l > 0) l = L[l];
      cnt += (R[i] - i) * (L[i] - l);
    }
    if (r <= n) {
			++r;
      while (a[r] < a[i] && r <= n) r = R[r];
//      cerr<<r;
      cnt += (i - L[i]) * (r - R[i]);
    }
//		cout<<l<<" "<<r<<" "<<cnt<<'\n';;
    ans += ll(cnt) * a[i];
	}

	cout<<ans;

   return 0;
}
