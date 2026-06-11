#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define rep(i,n) for(int i = 0;i < (n); i++)

int main(){
    int n,k;
    cin >> n >> k;
    int p[n];
    rep(i,n){
        int temp;
        cin >> temp;
        p[i] = temp;
    }
    double sum = 0;
    double largest = 0;
    for(int i = 0; i < n; i++){
        if(i < k){
            sum += (p[i]+1)/2.0;
            largest = sum;
        }
        else{
            sum = sum- (p[i-k]+1)/2.0 + (p[i]+1)/2.0;
        }
        if(largest < sum){
            largest = sum;
        }

    }
    cout << fixed << setprecision(12) << largest << endl;
}