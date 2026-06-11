#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> L(n);
    for(int i=0; i<n; i++){
        cin >> L.at(i);
    }
    sort(L.begin(), L.end());
    int ans=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum = L.at(i) + L.at(j);
            int l = j;
            int r = n;
            while(l+1<r){
                int mid = (l+r)/2;
                if(sum > L.at(mid)){
                    l=mid;
                }
                else r=mid;
            }
            ans += (l-j);
        }
    }
    cout << ans << endl;
}
