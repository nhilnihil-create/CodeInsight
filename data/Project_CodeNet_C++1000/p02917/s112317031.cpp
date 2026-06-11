#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n-1);
    for(int i=0; i<n-1; i++){
        cin >> b.at(i);
    }
    int ans=b.at(0)+b.at(n-2);
    for(int i=0; i<n-2; i++){
        ans+=min(b.at(i),b.at(i+1));
    }
    cout << ans << endl;
}