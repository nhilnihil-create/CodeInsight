#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int MAX_N,q;
int par[(int)2e5];
int ranks[(int)2e5];

void init(int n) {
    for (int i=0; i<n; i++){
        par[i] = i;
        ranks[i] = 0;
    }
}

int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if (x==y) return;

    if (ranks[x] < ranks[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if (ranks[x]==ranks[y]) ranks[x]++;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
  	cin >> MAX_N >> q;
    init(MAX_N);
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0){
            unite(b,c);
        }
        else{
            if(same(b,c)){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}