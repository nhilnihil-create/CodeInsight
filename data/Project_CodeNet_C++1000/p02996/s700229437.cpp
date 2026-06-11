#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long> time(n), dead(n);
    rep(i,n) cin >> time[i] >> dead[i];

    vector <pair <long,long> > set(n);
    rep(i,n) set[i].first = dead[i], set[i].second = time[i];

    sort(all(set));

    long sum=0;
    bool ok=true;

    for(int i=0; i<n; i++){
        sum += set[i].second;
        if(sum > set[i].first){
            ok=false;
            break;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}