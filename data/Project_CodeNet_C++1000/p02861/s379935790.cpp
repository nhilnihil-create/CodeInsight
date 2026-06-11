#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define ss second
#define ff first 


int main(){
    int n;
    cin >> n;
    vector<pair<int, pii> > a(n);
    for(int i=0; i<n; ++i){
        a[i].first = i;
        cin >> a[i].second.first >> a[i].second.second;
    }

    double ans=0;
    int xx = 0;
    do{
        double tempsum = 0;
        for(int i=1; i<n; ++i){
            tempsum += sqrt((a[i].ss.ff - a[i-1].ss.ff)*(a[i].ss.ff - a[i-1].ss.ff) + (a[i].ss.ss - a[i-1].ss.ss)*(a[i].ss.ss - a[i-1].ss.ss));
        }
        ans+=tempsum;
        ++xx;
    }while(next_permutation(a.begin(), a.end()));

    printf("%.6f", ans/xx);
}
