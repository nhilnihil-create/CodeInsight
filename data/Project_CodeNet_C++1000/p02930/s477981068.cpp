#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
int a[510][510];

void dfs(int l, int r, int now){
    if(l+1==r) return;
    int mid = (l+r)/2;
    srep(i,l,mid){
        srep(j,mid,r){
            a[i][j] = now;
        }
    }
    dfs(l,mid,now+1);
    dfs(mid,r,now+1);
}

int main() {
    int n;
    cin >> n;

    dfs(0,n,1);
    rep(i,n){
        srep(j,i+1,n) cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}


