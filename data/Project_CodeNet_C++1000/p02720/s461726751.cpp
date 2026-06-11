/*  /$$                                     /$$
      | $$                                    | $$
  /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$
 /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$$$$$$$| $$      | $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/
| $$  | $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$
|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$
 \_______/ \_______/ \_______/ \______/  \_______/ \_______/|__//$$$$$$ /$$$$$$
                                                               |______/|______/

*/
#include <bits/stdc++.h>
#define fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ln            cout << endl;
#define vi            vector<int>
#define vll           vector<long long>
#define sortl(vec)    sort(vec.begin(), vec.end());
#define sortr(vec)    sort(vec.rbegin(), vec.rend());
#define forn(i, x, n) for(long long i = x; i < n; i++)
#define revn(i, n, x) for(long long i = n; i >= x; i--)
#define in(vec)       for(auto &it : vec) cin >> it;
#define loop(vec)     for(auto &it : vec)
#define	out(vec)      for(auto &it : vec) cout << it << " "; ln
#define ll            long long
#define mod           1000000007
#define pb            emplace_back
#define mp            make_pair
#define um            unordered_map
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define f             first
#define s             second
#define pi            3.14159265359
#define o(x)		  cout << x << endl;
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

ll bS(ll l, ll r, ll x, vll arr) {
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

void primeFactors(ll n) {
	while (n % 2 == 0) {
		//cout << 2 << " ";
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			//cout << i << " ";
			n = n / i;
		}
	}

	if (n > 2)
		cout << n << " ";
}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modulo(ll a, ll b) {
	ll c = a % b;
	return (c < 0) ? c + b : c;
}

int main() {
// in(vec) works for size-defined type vectors

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	fastio
	ll t = 1;
	while (t--) {
		ll k;
		cin >> k;
		if (k <= 9) {
			o(k)
			return 0;
		}

		queue<ll>q;
		forn(i, 1, 10) {
			q.push(i);
		}

		k -= 9;
		ll n = 0;
		while (true) {
			ll head = q.front();
			q.pop();
			ll ld = head % 10;
			if (ld == 0) {
				q.push(head * 10 + ld);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}
				q.push(head * 10 + ld + 1);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}

			}
			else if (ld == 9) {
				q.push(head * 10 + ld - 1);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}
				q.push(head * 10);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}
			}
			else {
				q.push(head * 10 + ld - 1);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}
				q.push(head * 10 + ld);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}
				q.push(head * 10 + ld + 1);
				n++;
				if (n == k) {
					o(q.back());
					return 0;
				}

			}


		}


	}
	CLOCK
	return 0;
}

//Credits: https://www.youtube.com/watch?v=qZL8Oh9hW8E
//Credits: Editorial