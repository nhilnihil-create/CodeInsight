// Practice 40 hours a day to become Ling Ling
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Silent_voice
#define endl "\n"

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 2e5;

LL nLamp, nStep, lamps[MaxN], temp[MaxN];

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> nLamp >> nStep;
    for(int iLamp = 0 ; iLamp < nLamp ; ++iLamp) cin >> lamps[iLamp];
    while(nStep--){
        bool isChanged = 0;
        memset(temp, 0, sizeof temp);
        for(int iLamp = 0 ; iLamp < nLamp ; ++iLamp){
            LL lo = max(0LL, iLamp - lamps[iLamp]);
            LL hi = min(nLamp - 1, iLamp + lamps[iLamp]);
            temp[lo]++;
            temp[hi + 1]--;
        }
        for(int iLamp = 0 ; iLamp < nLamp ; ++iLamp){
            if(iLamp != 0) temp[iLamp] += temp[iLamp - 1];
            if(!isChanged && temp[iLamp] != lamps[iLamp]) isChanged = 1;
        }
        if(!isChanged) break;
        memcpy(lamps, temp, sizeof temp);
    }
    for(int iLamp = 0 ; iLamp < nLamp ; ++iLamp) cout << lamps[iLamp] << " ";

    return 0;
}