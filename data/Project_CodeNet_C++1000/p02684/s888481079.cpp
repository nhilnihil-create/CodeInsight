#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n,-1);
    b[0]=0;//a+1にはb[a]回後に着く

    int rs,rn;
    int nexttown=a[0];
    for(int i = 0; i < n; i++) {
        if(b[nexttown-1]==-1){
            b[nexttown-1]=i+1;
            int x=a[nexttown-1];
            nexttown=x;
        }

        else{
            rs=nexttown;
            rn=i+1-b[nexttown-1];
            break;
        }
    }
    int fr=b[rs-1];

    vector<int> c(rn);
    c[0]=rs;
    for(int i = 1; i < rn; i++) {
        c[i]=a[c[i-1]-1];
    }

    if(k<fr){
        for(int i = 0; i < n; i++) {
            if(b[i]==k) {
                cout << i+1 << endl;
                break;
            }
        }
    }
    else{
        k -= fr;
        k %= rn;
        cout << c[k] << endl;
    }

    return 0;
}