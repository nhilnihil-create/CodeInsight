#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}


int main() {
    srep(i,1,10){
        srep(j,1,10){
            cout << i << 'x' << j << '=' << i*j << endl;
        }
    }
    return 0;
}
 
 

