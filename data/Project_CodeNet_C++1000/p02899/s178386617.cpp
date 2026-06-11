#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x)          (int)x.size()
#define en             '\n'
#define sp             ' '
#define input(vec)     for(auto &a: vec)cin >> a;
#define output(vec)    for(auto &a: vec)cout << a << sp;cout << en;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc = 1, n, x, i;
    //cin >> tc;

    while(tc--){
        cin >> n;
        vector < int > bruh(n);
        for(i = 0;i < n;i++){
            cin >> x;
            bruh[x-1] = i + 1;
        }
        output(bruh);
    }
    return 0;
}
