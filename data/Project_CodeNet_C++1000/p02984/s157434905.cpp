#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
    }
    sum /= 2;
    ll temp = 0;
    for(int i=1;i<n;i++){
        if(i%2 == 1)temp+=A[i];
    }
    vector<ll> x(n,0);
    x[0] = sum - temp;
    for(int i=0;i<n-2;i++){
        x[i+1] = A[i] - x[i];
    }
    x[n-1] = A[n-1] - x[0];
    vector<ll> ans(n,0);
    for(int i=0;i<n;i++){
        ans[i] = x[i] * 2;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}