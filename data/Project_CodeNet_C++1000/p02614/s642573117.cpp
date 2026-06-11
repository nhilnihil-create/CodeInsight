#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 1000000000000000000LL
using namespace std;
int n,m,k;

int get(vector<string> &v, int x, int y){
    int cnt = 0;
    forr(i,n){
        if((1<<i)&x){
            forr(j,m){
                if( ((1<<j)&y) && v[i][j] == '#' ) cnt++;
            }
        }
    }
    return cnt;
}



void _sol(){
   // int n,m,k; 
    cin >> n >> m >> k;
    vector<string> v(n);
    forr(i,n) cin >> v[i];
    int ans = 0;
    int p = (1<<n), q =(1<<m);

  // cout << p << " " << q << "\n";
    forr(i,p){
        forr(j,q){
            if(get(v,i,j) == k) ans++;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) _sol();
}
