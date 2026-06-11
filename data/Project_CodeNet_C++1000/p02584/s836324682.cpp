#include <iostream>

using namespace std;

int main()
{
    /* x: current position
     * k: moving times
     * d: distance when moving once
     */
    long long x, k, d;
    long long times, ans;
    cin >> x >> k >> d;
    times = abs(x)/d;
    if(times >= k){
        ans = abs(x) - k*d;
        cout << ans << endl;
    }else {
        long long now = abs(x) - d*times;
        if((k-times)%2 == 0){
            ans = now;
        }
        else{
            ans = abs(now-d);
        }
        cout << ans << endl;
    }
    return 0;
}

