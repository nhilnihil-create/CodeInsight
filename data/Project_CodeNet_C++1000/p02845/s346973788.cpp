#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long Mod=1000000007;
    int n;
    cin >> n;
    //int a[100005];
    long long s=1;
    int c[100005];
    for(int i=0; i<n; i++) c[i] = 0;
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        //bool flag = true;
        if(x==0){
            if(c[0]==3){
                cout << 0 << endl;
                return 0;
            }
            s *= 3-c[x];
            s %= Mod;
            c[x]++;
        } else {
            if (c[x]==3 | c[x-1] <= c[x]) {
                cout << 0 << endl;
                return 0;
            }
            s *= c[x-1]-c[x];
            s %= Mod;
            c[x]++;
        }
    }
  
    cout << s << endl;
}