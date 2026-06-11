/*
20/7/27
無理、どうやってAを全探索するのか
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int best_score=0;
vector<int> a(60),b(60),c(60),d(60);
int N,M,Q;

void dfs(int A_num, int l_limit, vector<int> &A){
    if(A_num>N) return;
    for(int i=l_limit;i<=M;i++){
        A[A_num-1]=i;
        if(A_num==N){
            int score=0;
            for(int i=0;i<Q;i++){
                if((A[b[i]]-A[a[i]])==c[i]) score+=d[i];
            }
            //for(int i:A) cout << i << " ";
            //cout << endl;
            //cout << score << endl;
            best_score=max(best_score,score);
        }
        dfs(A_num+1,i,A);
    }
}

int main(){
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for(int i=0;i<Q;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> A(N,0);
    dfs(1,1,A);
    cout << best_score << endl;
}