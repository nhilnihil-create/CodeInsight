#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int s = p[0];
    int t = p[0];
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(s < p[i])
            s = p[i];
        else if(t > p[i]){
            t = p[i];
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}