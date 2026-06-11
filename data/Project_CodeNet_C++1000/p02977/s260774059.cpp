#include <bits/stdc++.h>
using namespace std;
#define double long double
#define x first
#define y second
#define mp make_pair
#define db double
#define pb push_back
#define all(a) a.begin(), a.end()
main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int T=n;
    while (T%2==0) T/=2;
    if (T==1){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (int i=2; i + 1 <= n; i+=2){
        cout << 1 << " " << i << endl;
        cout << i << " " << i+1 << endl;
        cout << 1 << " " << n+i+1 << endl;
        cout << n+i+1 << " " << n+i << endl;
    }
    cout << n+1 << " " << 3 << endl;
    if (n%2==0){
        for (int i=2; i < n; i++){
            int V = i^1^n;
            if (V < n){
                if (i%2==0) cout << n << " " << i << endl;
                else cout << n << " " << n+i << endl;
                if (V%2==0) cout << 2*n << " " << V << endl;
                else cout << 2*n << " " << n+V << endl;
                return 0;
            }
        }
    }
}