#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair<int,int> P;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int x[10],y[10];

double dist(int i,int j){
    int dx=x[i]-x[j];
    int dy=y[i]-y[j];
    return pow(dx*dx+dy*dy,0.5);
}


void solve(){
    int n,m;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> x[i] >> y[i];
    double sum=0;
    vector<int>v(n);
    for(int i=0;i<n;i++)v[i]=i+1;
    do{
        for(int i=0;i<n-1;i++) sum += dist(v[i], v[i+1]);
    }while(next_permutation(v.begin(),v.end()));
    int Factorial = 1;
    for(int i=2;i<=n;i++) Factorial *= i;
    cout << fixed << setprecision(10) << sum / Factorial << endl;
    return;
}

int main(){
    solve();
    return 0;
}



