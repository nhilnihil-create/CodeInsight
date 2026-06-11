#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N,a,b,c;
    cin >> N;
    a=0;
    b=0;
    c=0;
    ll i;
    ll t,m;
    ll ans=1;
    for(i=0;i<N;i++){
        cin >> t;
        m=1;
        if(a==t){
            if(b==a)m++;
            if(c==a)m++;
            a++;
        }else if(b==t){
            if(c==b)m++;
            b++;
        }else if(c==t){
            c++;
        }else m=0;
        ans=ans*m%1000000007;
    }
    cout << ans;
    return 0;
}
