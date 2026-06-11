#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    int k; cin >> k;
    int a, b; cin >> a >> b;
    for(int i = a; i <= b; ++i){
        if(i%k == 0){cout << "OK" << endl; return 0;}
    }
    cout << "NG" << endl;
}
