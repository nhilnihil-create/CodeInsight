#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;



int main(){
    int n, m; cin >> n >> m;
    vi a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int low=0, high=1e9+5;
    while(high-low > 1){
        int mid=low+(high-low)/2;
        ll sum=0;
        vector<priority_queue<int, vi, less<int>>> pque(m);
        priority_queue<int, vi, less<int>> award;
        for(int i=0; i<n; i++){
            if(a[i] > m) continue;
            pque[m-a[i]].push(b[i]);
        }
        for(int i=m-1; i>=0; i--){
            while(!pque[i].empty()){
                award.push(pque[i].top());
                pque[i].pop();
            }
            if(award.empty()) continue;
            sum+=award.top();
            award.pop();
        }
        if(sum >= mid) low=mid;
        else high=mid;
    }
    cout << low << endl;
    return 0;
}