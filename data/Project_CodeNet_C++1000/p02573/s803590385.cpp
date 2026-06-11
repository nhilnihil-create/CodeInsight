#include<bits/stdc++.h>
using namespace std;
#define int long long

int Size[200010], father[200010];

int findfa(int a){
    if(a == father[a]){
        return a;
    } else{
        return father[a] = findfa(father[a]);
    }
}

void merge(int a, int b){
    a = findfa(a);
    b = findfa(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        Size[a] += Size[b];
        father[b] = a;
    }
}


void testCase(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        Size[i] = 1;
        father[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == father[i]){
            ans = max(ans, Size[i]);
        }
    }

    cout << ans << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // int t; cin >> t;
    while(t--)
        testCase();
    
    return 0;
}