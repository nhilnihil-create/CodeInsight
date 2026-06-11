#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k , a, b;
    cin>>k>>a>>b;
    for(int i = a; i <= b; i++){
        if(i%k == 0){
            cout << "OK";
            return 0;
        }
    }
    cout << "NG";
}
