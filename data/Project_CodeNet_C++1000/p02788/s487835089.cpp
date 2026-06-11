#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <iostream>
#include <functional>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <set>
#include <iomanip>

#define ll long long
#define mod 1000000007
#define max_limit 1000005
using namespace std;

bool compare(const pair<ll, ll>&i, const pair<ll, ll>&j) {
    return i.first < j.first;
}

int main() {

    ll n;
    cin>>n;
    ll d;
    cin>>d;
    ll a;
    cin>>a;

    pair<ll, ll> post[n];

    for(int i = 0; i < n; i++) {
        cin>>post[i].first>>post[i].second;
    }
    sort(post, post + n, compare);

    // damage, inclusive end of application
    queue<pair<ll, ll>> q;
    ll ans{0};
    ll totalDamage{0};
    for(int i = 0; i < n; i++) {
        while(!q.empty() && post[i].first > q.front().second) {
            totalDamage -= q.front().first;
            q.pop();
        }

        if(post[i].second - totalDamage <= 0) {
            continue;
        }

        ll count{0};
        if((post[i].second - totalDamage)%a != 0) {
            count += 1;
        }
        count += (post[i].second - totalDamage)/a;
        totalDamage += count*a;
        ans += count;
        q.push(make_pair(count*a, post[i].first + 2*d));
    }


    cout<<ans<<'\n';
    return 0;
}
