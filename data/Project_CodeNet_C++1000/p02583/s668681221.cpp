#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
int main(){
    int n; cin >> n;
    vector<int> L(n);
    for(int i=0; i<n; i++) cin >> L[i];
    sort(L.begin(),L.end());
    long long ans = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++) {
                if(L[i]!=L[j]&&L[j]!=L[k]&&L[i]+L[j]>L[k])ans++;
            }
        }
    }
    cout << ans << endl;
}