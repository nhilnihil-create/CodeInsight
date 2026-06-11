#include <bits/stdc++.h>
using namespace std;
int main(void){
    long n; cin >> n;
    long cnt = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(v[i] + v[j] > v[k])cnt++;
            }
        }
    }
    cout << cnt << endl;
}
