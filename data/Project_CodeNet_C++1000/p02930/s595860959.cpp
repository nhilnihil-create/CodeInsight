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
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
vector<vector<int>> v(1000, vector<int> (1000,0));

void conq(int l,int r,int c){
    if(r-l<2) return;
    int m = (r + l)/2;
    for (int i = l; i < m; i++) {
        for (int j = m; j < r; j++) {
            v[i][j] = c;
        }
    }
    conq(l,m,c+1);
    conq(m,r,c+1);
}


int main(){
    int n;cin >> n;
    conq(0,n,1);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
