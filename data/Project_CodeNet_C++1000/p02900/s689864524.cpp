#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    ll A,B;
    cin >> A >> B;
    ll a = 2;
    set<ll> a_cnt;
    set<ll> b_cnt;
    ll A_copy = A;
    ll B_copy = B;
    while(A!=1&&a*a<=A_copy){
        while(A%a==0){
            A/=a;
            a_cnt.insert(a);
        }
        a++;
    }
    a_cnt.insert(1);
    a_cnt.insert(A);
    a = 2;
    while(B!=1&&a*a<=B_copy){
        while(B%a==0){
            B/=a;
            b_cnt.insert(a);
        }
        a++;
    }
    b_cnt.insert(1);
    b_cnt.insert(B);
    ll ans = 0;
    for(ll b:a_cnt){
        if(b_cnt.count(b)){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
