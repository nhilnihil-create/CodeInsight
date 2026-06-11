#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int n,m;
int par[N],rk[N];
unordered_map<int,int> h;
void init(int n){
    for(int i = 1;i<=n;i++){
        par[i] = i;
        rk[i] = 0;
    }
}

int find(int x){
    if(par[x] == x)  return x;
    else{
        return par[x] = find(par[x]);
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rk[x] < rk[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rk[x] == rk[y]) rk[x]++;
    }
}


int main(){
    cin >> n >> m;
    init(n);
    int ans = 0;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(!same(a,b)) {
            unite(a,b);
        }
    }
    for(int i =1;i<=n;i++) find(i);
    for(int i = 1;i<=n;i++){
        h[par[i]]++;
        ans = max(ans,h[par[i]]);
    }
    cout << ans << endl;
    return 0;
}