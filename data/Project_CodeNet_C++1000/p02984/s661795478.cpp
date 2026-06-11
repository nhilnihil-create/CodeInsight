#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> a(n);
    ll calc = 0;
    for(int i=0; i<n; i++){
        ll k;
        cin >> k;
        a.at(i) = k;
        if(i%2==0) calc+=k;
        else calc -= k;
    }
    calc /= 2;
    ans.at(0) = calc;
    for(int i=1; i<n; i++){
        ans.at(i) = a.at(i-1) - ans.at(i-1);
    }
    for(int i=0; i<n; i++){
        cout << 2*ans.at(i) << " ";
    }
}
