#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

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
    int h[n];
    rep(i, n){
        cin >> h[i];
    }
    h[0]--;
    for (int i = 1; i < n - 1; i++){
        if(h[i-1] < h[i]){
            h[i]--;
        }
    }
    rep(i, n-1){
        if(h[i] > h[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}