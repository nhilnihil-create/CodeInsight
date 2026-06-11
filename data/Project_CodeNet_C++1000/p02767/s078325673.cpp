#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    int x[n];
    for (int i=0; i<n; i++) cin>>x[i];
    sort(x, x+n);
    int mini = INT_MAX;
    for (int i=x[0]; i<=x[n-1]; i++){
        int sum = 0;
        for (int j=0; j<n; j++){
            int num = abs(x[j]-i);
            sum += num*num;
        }
        mini = min(mini, sum);
    }
    cout<<mini<<endl;
}

int main(){
    solve();
    Bye;
}