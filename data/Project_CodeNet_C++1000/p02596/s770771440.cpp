#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<ll>vec(k+1);
    vec[1] = 7%k;
    for(int i=2;i<=k;i++){
        vec[i] = (10*vec[i-1] + 7)%k;
    }

    for(int i=1;i<=k;i++){
        if(vec[i] == 0){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}