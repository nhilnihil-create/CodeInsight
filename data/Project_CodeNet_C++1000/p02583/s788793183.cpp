#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e2+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i];

    sort(a, a+n);

    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(a[i] + a[j] > a[k] && ((a[i] != a[j]) && (a[i] != a[k]) && (a[j] != a[k]))){
                    ans++;
                }
            }
        }
    }

    cout <<ans <<endl;

    return 0;
}
