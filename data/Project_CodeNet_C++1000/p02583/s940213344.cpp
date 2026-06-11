#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    int n, ans=0;
    int l[110];
    cin >> n;
    rep(i,n){
        cin >> l[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int a = l[i], b = l[j], c = l[k];
                if(a+b > c && b+c > a && c+a > b && a != b && b != c && a != c)ans++;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}