/*
      author : Nishikawa
      created: 07.08.2020 15:34:49
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
ll MAX = 1e18;

int main(){
    int N;
    cin >> N;
    ll product=1;
    ll tmp;
    vector<ll> a(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0 ;i<N; i++) if(a[i]==0){
        cout << "0" << endl;
        return 0;
    }
    for(int i=0; i<N; i++){
        ll input=a[i];
        ll cnt=1;
        ll now=0;
        while(input){
            now+=product*(input%10)*cnt;
            input/=10;
            cnt*=10;
            if(now>MAX){
                cout << "-1" << endl;
                return 0;
            }
        }
        product=now;
    }
    cout << product << endl;

    return 0;
}