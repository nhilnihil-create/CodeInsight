#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long double lb;

const int INF=1<<27;
const int MOD=(int)1e9+7;

int cnt;

void read(int *n, int a[])
{
    cin >> *n;
    rep(i,*n) cin >> a[i];
    return;
}


void insertion_sort(int a[], int n, int g)
{
    for(int i = g; i < n; i++){
        int v = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > v){
            a[j+g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }

    return;
}

void shell_sort(int a[], int n)
{
    cnt = 0;
    int m = 0;
    int g[100];
    int k = n;
    g[0] = n-1;
    for(m = 0; k > 0; k /= 2) m++;
    for(int i = 1; i < m; i++) g[i] = g[i-1]/2;
    cout << m << endl;
    rep(i,m) cout << g[i] << ' ';
    cout << endl;
    rep(i,m) insertion_sort(a, n, g[i]);
    return;
}

void print_array(int a[], int n)
{
    rep(i,n) cout << a[i] << endl;
}

int main(void)
{
    int n;
    int a[1000010];
    read(&n,a);
    shell_sort(a, n);
    cout << cnt << endl;
    print_array(a, n);
    return 0;
}