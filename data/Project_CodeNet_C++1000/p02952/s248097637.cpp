#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    if(n<10) {
        cout<<n<<endl;
        return 0;
    }
    int a = n;
    int b = 0;
    while(a) {
        a /= 10;
        b++;
    }
    int mul = 1;
    int ans = 0;
    rrep(i,b) {
        if(i%2){
            if(i!=b) ans += 9*mul;
            else ans += n-mul+1;
        }
        mul *= 10;
    }
    cout<<ans<<endl;

    return 0;
}
