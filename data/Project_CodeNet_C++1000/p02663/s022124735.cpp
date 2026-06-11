#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int h1,m1,h2,m2,k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>h1>>m1>>h2>>m2>>k;

    int t1 = h1*60 + m1;
    int t2 = h2*60 + m2;

    cout<<(t2-t1-k)<<endl;
    
    return 0;
}
