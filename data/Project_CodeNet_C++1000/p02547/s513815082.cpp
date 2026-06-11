#include<bits/stdc++.h>
//#include<atcoder/all>

typedef long long ll;

using namespace std;

int main(){
    int n;cin >> n;
    int check = 0;
    int ans = 0;
    for(int i = 0;i < n; i++){
        int x,y;
        cin >> x >> y;
        if(x != y)check = 0;
        else check ++;
        ans = max(ans, check);
    }
    if(ans >=3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}