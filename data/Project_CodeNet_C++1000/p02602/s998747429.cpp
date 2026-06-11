#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
const ll inf = 2147483647;
int n, m, k;
int a[200001];
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    k = n - m;
    for(int i = 1, j = m; j < n; i++, j++){
        if(a[i] < a[j + 1])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
