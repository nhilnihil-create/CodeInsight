#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())

int main() {
    lld N;
    cin >> N;
    vector<pi> G;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        G.push_back(make_pair(a,i+1));
    }
    asort(G);
    for (int i = 0; i < N; i++) {
        cout << G[i].second;
        if(i == N-1){
            cout << endl;
        } else {
            cout << " ";
        }
    }
}