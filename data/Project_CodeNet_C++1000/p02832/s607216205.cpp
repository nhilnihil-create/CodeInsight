#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i, n) for(i=0; i<n; i++)
#define pb push_back
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>bricks;
    int i, count = 0, index = 1;
    rep(i, n){
        int x;
        cin >> x;
        bricks.pb(x);
    }
    rep(i, n){
        if(bricks[i]==index){
            index++;
        }
        else{
            count++;
        }
    }
    if(count==n) cout << "-1\n";
    else cout << count << endl;
    return 0;
}