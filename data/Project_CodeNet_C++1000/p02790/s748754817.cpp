#include<bits/stdc++.h>

#define forw(m,i,n) for(i=m; i<n; i++)
#define done return 0
#define in(x) cin >> x
#define out(x) cout << x << endl
#define pb(x) push_back(x)
#define w(x) while(x--)
#define maxx 1000000000

using namespace std;

typedef long long ll;

 map<int,int>dig;

int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int a,b,i;
    in(a),in(b);
    if(a>b) {
        for(i=0; i<a; i++) {
            cout << b;
        }
    }
    else {
        for(i=0; i<b; i++) {
            cout << a;
        }
    }
    cout << endl;
    done;
}