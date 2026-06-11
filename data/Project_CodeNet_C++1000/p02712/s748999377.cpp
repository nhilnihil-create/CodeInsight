#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return (a<b);
}
 
int main(){
    int n; cin >> n;
    long long ans = 0;
    for(int i=1; i<=n; i++){
        if(i%3!=0 && i%5!=0) ans+=i;
    }
    cout << ans << endl;
    return 0;
}