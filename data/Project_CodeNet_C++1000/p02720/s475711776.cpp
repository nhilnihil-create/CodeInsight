#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    queue<ll> q;
    for(int i = 1; i < 10; i++) {
        q.push(i);
    }
    if(x<10){
        cout << x << endl;
        return 0;
    }
    x -= 9;
    ll ans=0;
    while(1) {
        ll s=q.front();
        q.pop();
        int y=s%10;
        if(y==9) {
            x-=2;
            q.push(s*10+8);
            q.push(s*10+9);
            if(x==0){
                ans=s*10+9;
                break;
            }
            if(x==-1){
                ans=s*10+8;
                break;
            }
        }
        else if(y==0){
            x-=2;
            q.push(s*10);
            q.push(s*10+1);
            if(x==0){
                ans=s*10+1;
                break;
            }
            if(x==-1){
                ans=s*10;
                break;
            }
        }
        else {
            x-=3;
            q.push(s*10+y-1);
            q.push(s*10+y);
            q.push(s*10+y+1);
            if(x==0){
                ans=s*10+y+1;
                break;
            }
            if(x==-1){
                ans=s*10+y;
                break;
            }
            if(x==-2){
                ans=s*10+y-1;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}