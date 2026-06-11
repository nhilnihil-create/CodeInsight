#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    int ans=10000000;
    for(int place=0;place<=100;place++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(place-x[i])*(place-x[i]);
        }
        ans=min(ans,sum);
    }
    cout << ans << endl;
}