#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(void)
{
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    rep(i,1000){
        int c[3] = {i/100, (i/10)%10, i%10};
        int e = 0;
        rep(i,n){
            if(c[e]+'0' == s[i]) e++;
        	if(e == 3) break;
        }
        if(e == 3) cnt++;
    }
    cout << cnt << endl;
    return 0;
}