#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 2147483647;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);
const ll LLMAX = 9223372036854775805;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll cu = 1000;
    ll stock = 0;
    //cout << cu << endl;
    for(int i=0;i<n-1;i++){
        if(a[i] < a[i+1]){
            stock = cu / a[i];
            cu += (a[i+1] - a[i]) * stock;
        }
        //cout << cu << endl;
    }
    cout << cu << endl;
}