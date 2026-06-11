#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define mp make_pair
#define FOR(i, n) for(i = 0; i < n; ++i)
typedef vector <int> vi;
typedef vector <LL> vll;
typedef pair<LL, LL> iPair;
const int MOD = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

    LL t = 1;
    LL i,j;
    // cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        set <iPair> s;
        vll arr(n), brr(n);
        FOR(i, n) cin>>arr[i];
        FOR(i, n) cin>>brr[i];
        FOR(i, n) s.insert({brr[i], i});
        LL ans = 0;
        while (!s.empty())
        {
            LL i = s.rbegin()->second;
            auto it = s.end();
            it--;
            s.erase(it);
            LL step = brr[(i - 1 + n) % n] + brr[(i + 1) % n];
            if((brr[i] - arr[i]) % step == 0)
            {
                ans += (brr[i] - arr[i]) / step;
                brr[i] = arr[i];
                continue;
            }
            if(step > (brr[i] - arr[i]))
            {
                cout<<"-1";
                return 0;
            }
            ans += brr[i] / step;
            brr[i] %= step;
            if(brr[i] < arr[i])
            {
                cout<<"-1";
                return 0;
            }
            s.insert({brr[i], i});
        }
        cout<<ans;
        


    }

	return 0;
}
