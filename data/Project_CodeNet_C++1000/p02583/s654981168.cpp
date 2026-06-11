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

int main(){
    int n;
    cin >> n;
    int l[n];
    rep(i, n){
        cin >> l[i];
    }
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    sort(l, l + n);
    int ans = 0;
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                if (l[i] + l[j] > l[k] && l[i] != l[j] && l[j] != l[k]){
                    ans++;
                }
                
            }
        }
    }
    cout << ans << endl;
}