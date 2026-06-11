#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef long long ll;
#define range(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) range(i,0,n)
#define INF 10000000000 //10^10
#define PI 3.141592

int main(){
    int n;
    cin >> n;
    vector<vint> A(n,vint(n,0));
    rep(i,n){
        int u,k;
        cin >> u >> k;
        rep(j,k){
            int v;
            cin >> v;
            A[u-1][v-1]=1;
        }
    }
    rep(i,n){
        rep(j,n){
            cout << A[i][j];
            if(j<n-1) cout << ' ';
        }
        cout << endl;
    }
}

