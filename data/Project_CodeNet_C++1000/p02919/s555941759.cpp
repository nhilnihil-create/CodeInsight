/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1001;
long long n, res;
int a[N], lmax[N],rmax[N], pos[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        lmax[i] = i - 1;
		rmax[i] = i + 1; 
    }
    for (int i = 1; i <= n; i++) {
        int lpos1 = lmax[pos[i]],
			lpos2 = lmax[lpos1],
         	rpos1 = rmax[pos[i]],
        	rpos2 = rmax[rpos1];
        if(lpos1 != 0)
			 res += 1LL * i * (lpos1 - lpos2) * (rpos1 - pos[i]);
        if(rpos1 != n + 1)
		 	res += 1LL * i * (pos[i] - lpos1) * (rpos2 - rpos1);
        lmax[rpos1] = lpos1;
        rmax[lpos1] = rpos1;
    }
    cout << res << "\n";
}
