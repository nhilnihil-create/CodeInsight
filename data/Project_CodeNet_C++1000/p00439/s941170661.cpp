#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define MAX 1000000000
#define MIN -10000000000

#define ll long long

using namespace std;
int main() {

        ll n,k,i,j,temp,last,maxx;
        do {
            cin >> n >> k;
            if(k==0&&n==0)break;
            vector<ll> a(n);
            vector<ll> s(n + 1);
            for (i = 0; i < n; i++) {
                cin >> a[i];
            }
            //cin >> temp >> temp;
            s[0] = 0;
            for (i = 0; i < n; i++) {
                s[i + 1] = s[i] + a[i];
            }
            maxx = a[k - 1] + a[0];
            for (i = 0; i < n - k + 1; i++) {
                //   cout << s[i+k]-s[i] << endl;
                maxx = max(s[i + k] - s[i], maxx);
            }
            cout << maxx << endl;
        }while(k!=0&&n!=0);

//cout << "aaa" << endl;

    return 0;
}
