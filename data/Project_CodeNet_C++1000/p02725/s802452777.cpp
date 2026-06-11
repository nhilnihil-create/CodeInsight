#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, n;
ll a[200111];
ll segments[200111];
ll max_seg = 0;
ll count_max_segs = 0;
ll ans = 0;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n ; i++){
        if (i < n)
            segments[i] = a[i] - a[i - 1];
        else
            segments[i] = k - a[i - 1] + a[0];

        if (segments[i] > max_seg){
            max_seg = segments[i];
        }
        
    }

    for (int i = 1; i <= n ; i++){
        if (segments[i] == max_seg)
            count_max_segs++;
    }
    for (int i = 1; i <= n ; i++){
        if (segments[i] < max_seg)
            ans+=segments[i];
    }

    ans += (count_max_segs - 1)*max_seg;

    cout << ans << endl;
    return 0;
}