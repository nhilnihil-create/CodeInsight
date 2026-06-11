#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 10000000;
int cnt[MAX+1];
bitset<MAX+1> marked;

void sieve() {
    fill(cnt, cnt+MAX+1, 1);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        cnt[i]++;
        for (int j = i*2; j <= MAX ; j += i) {
            int n = j, c = 1;
            while (n%i == 0) n /= i, c++;
            cnt[j] *= c;
            marked[j] = true;
        }
    }
}

int main() {
	sieve();
	int n; cin>>n;
	unsigned long long ans = 0;
	for(ll i=1; i<=n; i++){
		ans+=(i*cnt[i]);
	}
	cout<<ans<<endl;
}
