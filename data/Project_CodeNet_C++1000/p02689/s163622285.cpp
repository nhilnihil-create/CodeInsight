#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int,int>;
struct trio{
    int first;
    int second;
    int third;
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> vec(n+1);
    vector<int> ans(n+1,0);
    ans[0] = 1;
    vec[0] = 0;
    rep(i,n){
        int h;
        cin >> h;
        vec[i+1] = h;
    }
    rep(i,m){
        int h1,h2;
        cin >> h1 >> h2;
        if (vec[h1] == vec[h2]){
            ans[h1] = 1;
            ans[h2] = 1;
        }
        else if(vec[h1] > vec[h2]){
            ans [h2] = 1;
        }
        else {
            ans [h1] = 1;
        }
    }
    int a = 0;
    rep(i,n+1){
        if (ans[i] == 0){
            a++;
        }
    }
    cout << a << endl;
}