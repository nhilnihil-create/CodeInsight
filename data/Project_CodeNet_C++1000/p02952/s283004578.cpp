#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main(){

    int N;
    cin>>N;
    int ans=0;
    for(int i=1;i<=N;i++){
        string s=to_string(i);
        if(s.length()%2==1)ans++;
    }
    cout << ans << endl;

    return 0;
}