#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5+10;
const int MAX = 1e5+10;
const double exps = 1e-8;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }
int a[] = {1, 1, 1, 2, 1, 2, 1, 5,  2, 2, 1, 5, 1, 2, 1, 14,
           1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51}; 
int main() {
    int k;
    cin>>k;
    cout<<a[k-1];
}