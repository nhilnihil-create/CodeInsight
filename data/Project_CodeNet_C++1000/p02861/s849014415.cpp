#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<cmath>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }
    vector<vector<double> > dist(n, vector<double>(n)); 
    rep(i, n){
        rep(j, n){
            double dx = x[i] - x[j], dy = y[i] - y[j];
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
    vector<int> perm;
    rep(i, n) perm.push_back(i);
    double ans = 0;
    double num = 0;
    do{
        num += 1;
        for (int i = 0; i < n - 1; i++){
            ans += dist[perm[i]][perm[i+1]];
        }
    }while(next_permutation(perm.begin(), perm.end()));
    ans /= num;
    printf("%.10lf\n", ans);
}