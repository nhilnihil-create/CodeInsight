#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    rep(i,n){
        a[i] = s[i] - '0';
        a[i]--;
    } 

    int two[n] = {};
    srep(i,1,n){
        two[i] = two[i-1];
        int cnt = 0;
        int ii = n - i;
        while(ii%2==0){
            two[i]++;
            ii /= 2;
        }
        ii = i;
        while(ii%2==0){
            two[i]--;
            ii /= 2;
        }
    }
    rep(i,n/2){
        two[n-1-i] = two[i];
    }
    rep(i,n){
        if(two[i] == 0) two[i] = 1;
        else two[i] = 0;
    }
    ll flag = 0;
    rep(i,n){
        if(a[i] == 1){
            flag += two[i];
            flag %= 2;
        }
    }

    if(flag){
        cout << 1 << endl;
        return 0;
    }

    rep(i,n){
        if(a[i] == 1){
            cout << 0 << endl;
            return 0;
        }
    }

    flag = 0;
    rep(i,n){
        if(a[i] == 2){
            flag += two[i];
            flag %= 2;
        }
    }

    if(flag){
        cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}


