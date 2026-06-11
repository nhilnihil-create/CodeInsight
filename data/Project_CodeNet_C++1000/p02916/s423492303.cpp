#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)


int main(){
    int N;
    cin >> N;
    int a[N], b[N], c[N-1];
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];
    rep(i,N-1) cin >> c[i];
    int sum=0;
    rep(i,N){
        sum += b[i];
        if(i>0 && a[i]==a[i-1]+1){
            sum+=c[a[i-1]-1];
        }
    }
    cout << sum << endl;
    return 0;
}