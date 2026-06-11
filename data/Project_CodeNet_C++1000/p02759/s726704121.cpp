#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    int N;
    cin >> N;
    int ans=N/2;
    if(N%2==1) {
        ans++;
    }
    cout << ans << endl;
}
