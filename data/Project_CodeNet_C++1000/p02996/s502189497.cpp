#include <bits/stdc++.h>
using namespace std;

//long long型(64bit整数)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<ll, ll> > pairs(n);
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        pairs[i] = make_pair(b, a);
    }
    //締め切りが早い順にソート
    sort(pairs.begin(), pairs.end());

    bool isok = true;
    ll time = 0;
    for(int i=0; i<n; i++){
        time += pairs[i].second;
        if(time > pairs[i].first){
            isok = false;
            break;
        }
    }
    if(isok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}