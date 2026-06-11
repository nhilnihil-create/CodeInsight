#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,k,s,d=1e9;
    cin >> n >> k >> s;
    if(s==int(1e9)) d = 1;
    for(int i=0;i<k;i++){
        cout << s << ' ';
    }
    for(int i=k;i<n;i++){
        cout << d << ' ';
    }
    cout << endl;
}