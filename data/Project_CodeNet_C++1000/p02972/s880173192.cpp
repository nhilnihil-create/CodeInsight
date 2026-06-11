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
    int a[n];
    rep(i, n){
        cin >> a[i];
    }
    bool box[n];
    int m = 0;
    for (int i = n; i > 0; i--){
        int num = 0;
        for (int j = 2 * i; j <= n; j += i){
            if(box[j-1]) num++;
        }
        // cout << i << " " << num << endl;
        if(num % 2 != a[i-1]) {
            box[i-1] = true;
            m++;
        }else box[i-1] = false;
    }
    // rep(i, n){
    //     if(box[i]) cout << 1 << endl;
    //     else cout << 0 << endl;
    // }
    cout << m << endl;
    rep(i, n){
        if(box[i]) cout << i + 1 << " ";
    }cout << endl;
}