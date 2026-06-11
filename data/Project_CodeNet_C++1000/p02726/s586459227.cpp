#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y; 

    vector<int> ks(n);

    for(int i=1; i <= n-1; i++){
        for(int j=i+1; j<=n; j++){
            int m = min({j-i, abs(x-i) + 1 + abs(y-j), abs(y-i) + 1 + abs(x-j)});
            ks[m]++;
        }
    }

    for(int k=1;k<n;k++){
        cout << ks[k] << endl;
    }
}