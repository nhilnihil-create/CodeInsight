#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>> n;

    vector<int> L(n);
    for(int i=0; i<n; i++){
        cin>> L[i];
    }

    sort(L.begin(), L.end());

    int ans = 0;
    for(int i=n-1; i>=0; --i){
        for(int j=i-1; j>=0; --j){
            int d = L.end() - lower_bound(L.begin(), L.end(), L[i]+L[j]);
            ans += n-1 - i - d;
        }
    }
    cout<< ans <<endl;

    return 0;
}