#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int> que;
const ll INF = 10000000000;

int main(){
    int x; cin >> x;
    for(int a=1; a<1000; ++a){
        ll a5 = 1;
        for(int i=0; i<5; ++i){a5 *= a;}
        for(int b=-1000; b<1000; ++b){
            ll b5 = 1;
            for(int i=0; i<5; ++i){b5 *= b;}
            if(a5-b5==x){
                printf("%d %d\n", a , b);
                return 0;
            }
        }
    }
    return 0;
}