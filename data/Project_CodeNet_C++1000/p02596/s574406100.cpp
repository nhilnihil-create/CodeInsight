#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

int main(){
    int k,l;cin>>k;
    if(k%2==0||k%5==0){
        cout<<-1<<endl;
        return 0;
    }else if(k%7==0){
        l = 9*k/7;
    }else l = 9*k;
    int x,r;
    int sz = to_string(l).length();
    x = pow(10,sz);
    r = (int)x % l;
    while(r!=1){
        r *= 10;
        r = r%l;
        sz++;
    }
    cout<<sz<<endl;
    return 0;
}