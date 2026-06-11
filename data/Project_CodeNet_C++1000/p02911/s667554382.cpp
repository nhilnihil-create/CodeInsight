#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N,K,Q; cin>>N>>K>>Q;
    vi score(N,0);
    for (int i = 0; i < Q; i++){
        int a; cin>>a; a--;
        score[a]++;
    }
    for (int i = 0; i < N; i++){
        if(score[i]>Q-K)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}