#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k,x;
    cin >> n;
    cin >> k;
    vector<int> a(n, 0);
    for(int i=0;i<k;i++){
        int j; cin >> j;
        while(j--){
            cin >> x, --x;
            a[x] = 1;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)++cnt;
    }
    cout << cnt;
    cout << '\n';
    return 0;
}