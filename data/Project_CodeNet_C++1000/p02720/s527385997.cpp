#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    queue <ll> q;
    for(int i=1; i<10; i++) q.push(i);

    ll ans = 0;
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        n--;
        if(n==0){
            ans = a;
            break;
        }

        ll r = a%10;
        if(r==0){
            q.push(10*a);
            q.push(10*a+1);
        }
        else if(r==9){
            q.push(10*a+8);
            q.push(10*a+9);
        }
        else{
            q.push(10*a+r-1);
            q.push(10*a+r);
            q.push(10*a+r+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
