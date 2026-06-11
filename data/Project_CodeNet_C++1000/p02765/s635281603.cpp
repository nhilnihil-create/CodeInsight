#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    int N,R;
    cin >> N >> R;
    int ans;
    if(N<10) {
        ans=R+100*(10-N);
    }
    else{
        ans=R;
    }
    cout << ans << endl;
}
