#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
    if(x%y==0)return y;
    else return gcd(y,x%y);
}

int main(){
    /* A
    int n;
    cin >> n;
    bool check = false;
    for(int i=0;i<3;i++){
        if(n%10 == 7)check = true;
        n/=10;
    }
    cout << ((check)? "Yes": "No") << endl;*/

    /* B
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for(int i=1;i<=n;i++){
        if(i%3!=0&&i%5!=0)ans+=i;
    }
    cout << ans << endl;*/

    int k;
    cin >> k;
    int ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                ans += gcd(gcd(i,j),l);
            }
        }
    }
    cout << ans << endl;
    return 0;
}