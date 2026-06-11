#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

void fill(char mat[10][10],char temp[10][10]){
    rep(i,7) rep(j,7) temp[i][j]=mat[i][j];
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    char mat[10][10],temp[10][10];
    int b=0;
    rep(i,n) rep(j,m) {
        cin>>mat[i][j];
        if(mat[i][j]=='#')
        b++;
    }
    int row=(1<<n)-1;
    int col=(1<<m)-1;
    ll count=0,tmp=b;
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            fill(mat,temp);
            tmp=b;
            for(int k=0;k<n;k++){
                if(i&(1<<k)){
                    for(int l=0;l<m;l++) {
                        if(temp[k][l]=='#') tmp--,temp[k][l]='.';

                    }
                }
            }
            for(int k=0;k<m;k++){
                if(j&(1<<k)){
                    for(int l=0;l<n;l++) {
                        if(temp[l][k]=='#') tmp--,temp[l][k]='.';

                    }
                }
            }
            if(tmp==k) count++;
        }
    }

    cout<<count<<endl;

}

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}