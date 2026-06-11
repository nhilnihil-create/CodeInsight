#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int MAX_NUM = 1000000;
main(){
    vector<int> V,W;
    for(int i = 1;i * (i + 1) * (i + 2) / 6 <= MAX_NUM;i++){
        int num = i * (i + 1) * (i + 2) / 6; 
        V.push_back(num);
        if(i % 4 == 1)W.push_back(num);
    }
    vector<int> t1(MAX_NUM,INF),t2(MAX_NUM,INF);
    t1[0] = t2[0] = 0;
    rep(i,0,V.size()){
        rep(j,0,MAX_NUM){
            if(j + V[i] > MAX_NUM)break;
            t1[j + V[i]] = min(t1[j + V[i]], t1[j] + 1);
        }
    }
    rep(i,0,W.size()){
        rep(j,0,MAX_NUM){
            if(j + W[i] > MAX_NUM)break;
            t2[j + W[i]] = min(t2[j + W[i]], t2[j] + 1);
        }
    }
    int N;
    cin >> N;
    while(N){
        cout << t1[N] << " " << t2[N] << endl;
        cin >> N;
    }
}
