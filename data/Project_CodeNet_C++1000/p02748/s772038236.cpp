#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INF = 1LL << 60;

int main(){
    int A,B,M; cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    int x,y,c;
    long long  ans = INF;

    for(int i=0;i<A;i++) cin >> a[i];
    for(int i=0;i<B;i++) cin >> b[i];
    for(int i=0;i<M;i++){
        cin >> x >> y >> c;
        x--; y--;
        if(ans > a[x]+b[y]-c) ans = a[x]+b[y]-c;
    }

    sort(a.begin(),a.end()) ;
    sort(b.begin(),b.end()) ;
    int nodis = a[0]+b[0];
    if(nodis < ans) ans = nodis;
    cout << ans << endl;
}
