#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int l[200010];
int r[200010];

int main(){
    int N,K,C; cin >> N >> K >> C;
    string s; cin >> s;
    vector<int> ind;
    for(int i=0;i<N;i++){
        if(s[i]=='o') ind.push_back(i+1);
    }
    int l[K+1];
    int r[K+1];
    int len=ind.size();
    l[0]=ind[0];
    int cur=0;
    for(int i=1;i<K;i++){
        while(ind[cur]<=l[i-1]+C){
            cur++;
        }
        l[i]=ind[cur];
    }
    r[K-1]=ind[len-1];
    cur=len-1;
    for(int i=K-2;i>=0;i--){
        while(r[i+1]<=ind[cur]+C) cur--;
        r[i]=ind[cur];
    }
    for(int i=0;i<K;i++){
        if(l[i]==r[i]){
            cout << l[i] << endl;
        }
    }
}