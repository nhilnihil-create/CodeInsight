#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
bool is_runrun(ll x){
    bool runrun = true;
    int keta = x%10;
    while(x!=0){
        int old_keta=keta;
        keta=x%10;
        if(old_keta-keta<= 1 && keta-old_keta<=1){
            x /= 10;
            continue;
        }
        else{
            runrun = false;
            break;
        }
    }
    return runrun;
}
*/

int main(){
    int k;
    cin >> k;
    
    queue<ll> q;
    for(int i=1; i<=9; i++){
        q.push(i);
    }
    ll front;
    for(int i=0; i<k; i++){
        front = q.front();
        if(front%10 != 0){
            q.push(10*front+(front%10)-1);
        }
        q.push(10*front+(front%10));
        if(front%10 != 9){
            q.push(10*front+(front%10)+1);
        }
        q.pop();
    }
    cout << front << endl;
}
