#include <bits/stdc++.h>

#define fr first
#define se second

using namespace std;

const long long N = 3e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

int n;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        a[x] ++;
    }
    sort(a + 1, a + n + 1);
    vector<int> p(n + 1, 0);
    for(int i = 1; i <= n; i ++){
        p[i] = p[i - 1] + a[i];
    }
    int res = n;
    for(int k = 1; k <= n; k ++){
        while(true){
            int l = 0, r = n;
            while(l < r){
                int m = (l + r) / 2;
                if(a[m + 1] < res){
                    l = m + 1;
                }
                else{
                    r = m;
                }
            }
            int s = p[l] + (n - l) * res;
            if(s >= k * res){
                break;
            }
            res --;
        }
        cout << res << "\n";
    }
}

