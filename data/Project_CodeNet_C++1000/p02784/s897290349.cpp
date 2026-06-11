#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n , h;
int a[MAXX];

int main()
{
    _FastIO;
    cin >> h >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        h -= a[i];
    }
    if(h > 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}
