#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 100000;
ll mod = INF;

int n;
int a[maxn];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    // n/2-1 n/2
    cout << a[n/2]-(a[n/2-1]+1)+1<<endl;
    return 0;
}