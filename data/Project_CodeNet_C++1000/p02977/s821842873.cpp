#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    int n;cin >> n;
    for (int i = 0; i < 20; i++) {
        if(n==(1<<i)){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    if(n%2==1){
        for (int i = 2; i <= n; i++) {
            cout << 1 << " " << i << endl;
        }
        for (int i = 2; i <= n; i++) {
            if(i%2==0) cout << n+i << " " << i+1 << endl;
            else cout << n+i << " " << i-1 << endl;
        }
        cout << 1+n << " " << n+2 << endl;
    }
    else{
        int t=n,u=0;
        for (int i = 30; i >=0 ; i--) {
            if(n&(1<<i)){
                t-=1<<i;
                u=1<<i;
                break;
            }
        }
        for (int i = 2; i <= n-1; i++) {
            cout << 1 << " " << i << endl;
        }
        for (int i = 2; i <= n-1; i++) {
            if(i%2==0) cout << n+i << " " << i+1 << endl;
            else cout << n+i << " " << i-1 << endl;
        }
        cout << n+1 << " " << 2+n << endl;
        cout << n << " " << (t^1) << endl;
        cout << n+n << " " << u << endl;
    }
    return 0;
}
