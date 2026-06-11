#include <bits/stdc++.h>
using namespace std;
long f(int n){
    long a = 1;
    for(int i=2;i<n+1;i++){
        a *= i;
    }
    return(a);
}
int main(){
    int n; cin >> n;
    double a = 0;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++)cin >> v[i][0] >> v[i][1];
    sort(v.begin(),v.end());
    do{
        for(int i=1;i<n;i++){
            a += (double)sqrt(pow(v[i][0]-v[i-1][0],2)+pow(v[i][1]-v[i-1][1],2));
        }
    }while(next_permutation(v.begin(),v.end()));
    double ans = a/f(n);
    cout << setprecision(20) << ans << endl;
}    