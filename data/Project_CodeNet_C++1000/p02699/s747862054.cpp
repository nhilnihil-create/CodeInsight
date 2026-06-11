#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int s,w; cin >> s >> w;
    if(s <= w) cout << "unsafe" << endl;
    else cout << "safe" << endl;
    return 0;
}