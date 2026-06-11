#include<bits/stdc++.h>>

using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, int> pi;

lli lcm(lli a, lli b) {return (a*b)/__gcd(a, b);}

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    while(n--){
        int x;
        cin >> x;
        mp[x]++;
    }
    if(mp.size() == 1 && mp.begin()->first == 0){
        printf("Yes\n");
        return 0;
    }
    auto xx = mp.begin();
    auto y = mp.begin();
    y++;
    if(mp.size() == 2 && xx->second*2 == y->second && xx->first == 0){
        printf("Yes\n");
        return 0;
    }
    bool fl = mp.size()==3;

    int x = mp.begin()->second;
    for(auto it: mp){
        if(it.second != x){
            fl = false;
        }
    }

    if(mp.size() == 3){
        auto it = mp.begin();
        x = it->first;
        it++;
        int y = it->first;
        it++;
        int z = it->first;
        x = x^y;
        if(x != z){
            fl = false;
        }
    }
    cout << (fl? "Yes\n": "No\n");

    return 0;
}
