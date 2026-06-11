#include<bits//stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    
    long long x,l;
    vector<pair<long long , long long>> a;
    for(long long i = 0; i < N; i++){
        cin >> x >> l;
        a.push_back(make_pair(x + l, x - l));
    }
    sort(a.begin(),a.end());
    long long now = -(1LL<<60);
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i].second < now) continue;
        ans++;
        now = a[i].first;
    }
    cout << ans << endl;
}