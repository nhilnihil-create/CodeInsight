#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
typedef pair<int,int> P;

int N; 
vector<deque<int>> A(1010);

vector<P> match;

// kさんが試合をできればmatchに代入する
void check(int i){
    if(A[i].size() == 0) return;

    int j = A[i].front();
    if(A[j].front() == i){
        if(i > j) swap(i,j);
        match.push_back(P(i,j));
    }
}
 
int main(){
    cin >> N;
 
    rep(i, N) rep(j, N-1){
        int a; cin >> a; a--;
        A[i].push_back(a);
    }

    rep(i, N) check(i);

    int ans = 0;
    while(!match.empty()){
        ans++;
        
        sort(match.begin(), match.end());
        match.erase(unique(match.begin(),match.end()),match.end());

        vector<P> prev_match; swap(prev_match, match);

        for(P p : prev_match){
            int i = p.first, j = p.second;
            A[i].pop_front(); A[j].pop_front();
        }

        for(P p : prev_match){
            int i = p.first, j = p.second;
            check(i); check(j);
        }
    }

    rep(i, N){
        if(A[i].size() != 0){
            cout << -1 << endl; return 0;
        }
    }

    cout << ans << endl;
}