#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)

bool comp(pair<int,int> l, pair<int,int> r) {
  if (l.second != r.second) return l.second > r.second;
  else return l.first > r.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> task(n);
    rep(i,0,n) cin >> task[i].first >> task[i].second;
    sort(task.begin(), task.end(), comp);
    int now = task[0].second;
    rep(i,0,n){
        now = min(now, task[i].second);
        now -= task[i].first;
        if(now < 0) break;
    }
    if(now < 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}