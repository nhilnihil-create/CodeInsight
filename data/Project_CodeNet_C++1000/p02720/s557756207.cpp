#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}
template<typename S>
void print(S a){
    cout<<a<<endl;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    cin>>k;
    queue<ll> a;
    for(int i=1;i<10;i++){
        a.push(i);
    }
    ll tmp;
    int cnt=0;
    while(cnt<k){
        tmp = a.front();
        a.pop();
        int t = tmp%10;
        switch(t){
            case 0:
                a.push(tmp*10+t);
                a.push(tmp*10+t+1);
                break;
            case 9:
                a.push(tmp*10+t-1);
                a.push(tmp*10+t);
                break;
            default:
                a.push(tmp*10+t-1);
                a.push(tmp*10+t);
                a.push(tmp*10+t+1);
                break;
        }
        cnt++;
    }
    fin(tmp);

}
