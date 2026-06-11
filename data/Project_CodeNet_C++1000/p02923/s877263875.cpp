#include <bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
    vector <long> h(n);
    for(long i = 0; i < n; i++){
        cin >> h[i];
    }
    long ans = 0;
    long ansMax = 0;
    for(long i = 1; i < n; i++){
        if(h[i]<=h[i-1]){
            ans++;
        }else{
            ans = 0;
        }
        ansMax = max(ans,ansMax);
    }
    cout << ansMax << endl;
    return 0;
}