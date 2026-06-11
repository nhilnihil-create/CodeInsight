#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int tot;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot^=a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=a[i]^tot;
        cout<<b[i]<<' ';
    }
    return 0;
}