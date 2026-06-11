#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<bits/stdc++.h>
#define Fast ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;
int fac(int n)
{
    int fct = 1;
    for(int i=2; i<=n; i++) fct *= i;
    return fct;
}
int main() {
    Fast;
    int n;
    cin >> n;
    vector<pair<int, int>> cords;
    int i;
    for(i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        cords.pb(mp(x, y));
    }
    int j;
    double len = 0;
    for(i=0; i<n-1; i++){
        for(j=i; j<n; j++){
            len += sqrt((cords[i].first - cords[j].first)*(cords[i].first - cords[j].first) + (cords[i].second - cords[j].second)*(cords[i].second - cords[j].second));
        }
    }
    //double avg = (2.0*len)/(1.0*fac(n)*n) << endl;
    double ans = len*2/n;
    std::cout << std::fixed<<std::setprecision(19);
    cout << ans << endl;
    return 0;
}