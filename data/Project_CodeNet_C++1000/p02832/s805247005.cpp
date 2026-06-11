#include <bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
    vector <long> a(n);
    vector <long> snuke;
    long cnt = 1;
    long ans = 0;
    for(long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]==cnt){
            snuke.push_back(a[i]);
            cnt++;
        }
    }
    if(snuke.size()==0){
        ans = -1;
    }else{
        ans = n-snuke.size();
    }
    cout << ans << endl;
    return 0;
}