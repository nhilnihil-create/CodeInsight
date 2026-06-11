#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    /**/
    int ans = 0;
    int nxt = 1;

    for(int i = 0;i < n;i++){
        if(nxt == a[i]) nxt++;
        else ans++;
    }
    if(ans != n){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}