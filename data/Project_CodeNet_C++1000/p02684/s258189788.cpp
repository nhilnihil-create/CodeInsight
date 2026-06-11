#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 200010;
ll a[N];
bool vis[N];

vector<ll> vec;

int main(){
    ll n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> a[i];

    ll buffer = 1;

    for (int i = 0; i < n; i++) {
		vis[buffer] = 1;
        vec.push_back(buffer);
		buffer = a[buffer - 1];
        if (vis[buffer] == 1) {
            break;
        }
    }

    auto it = find(vec.begin(), vec.end(), buffer);

    ll Length = vec.end() - it;

    ll step = it - vec.begin();

    ll now;
    if (k > step) {
        now = (k - step) % Length;
    } else {
        now = (k - step);
    }
    printf("%lld\n", vec[step + now]);
}