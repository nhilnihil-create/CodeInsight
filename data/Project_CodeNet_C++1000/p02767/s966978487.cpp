#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> X(n);
    int ans =0;
    for(int i=0; i<n; i++){
        cin >> X.at(i);
        ans += X.at(i)*X.at(i);
    }
    for(int p=1; p<=100; p++){
        int power=0;
        for(int i=0; i<n; i++){
            power += (p-X.at(i))*(p-X.at(i));
        }
        ans = min(ans, power);
    }
    cout << ans << endl;
}