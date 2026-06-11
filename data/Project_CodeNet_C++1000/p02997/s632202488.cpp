#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    if(k>((n-1)*(n-2)/2)){
        cout << -1 << endl;
        return 0;
    }
    int count=(n-1)*(n-2)/2;
    cout << ((n*(n-1))/2)-k << endl;
    rep(i,n-1){
        for(int j=i+1; j<n; j++){
            if(i==0){
                cout << i+1 << ' ' << j+1 << endl;
                continue;
            }
            if(count<=k) return 0; 
            cout << i+1 << ' ' << j+1 << endl;
            k++;
        }
    }
return 0;
}
