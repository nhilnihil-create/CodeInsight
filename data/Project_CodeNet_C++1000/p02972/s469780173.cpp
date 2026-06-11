#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b(n);
    b=a;
    for(int i = n/2; i >= 1; i--) {
        int sum=0;
        for(int j = 2*i; j <= n; j+=i) {
            sum += b[j-1];
        }
        if(b[i-1]%2 != sum%2) b[i-1]=1;
        else b[i-1]=0;
        
    }

    for(int i = 0; i < n; i++) {
        if(b[i]%2==0) b[i]=0;
        else b[i]=1;
    }

    vector<int> c;
    for(int i = 0; i < n; i++) {
        if(b[i]==1) c.push_back(i+1);
    }

    cout << c.size() << endl;
    if(c.size()==0) return 0;

    for(int i = 0; i < c.size()-1; i++) {
        cout << c[i] << ' ' ;
    }
    cout << c[c.size()-1] << endl;

    return 0;
}