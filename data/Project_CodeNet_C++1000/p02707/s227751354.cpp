#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> cnt(n, 0);
    for(int i=2; i<=n; i++){
        int a;
        cin>> a;
        a--;
        cnt[a]++;
    }
    for(int i=0; i<n; i++){
        cout<<cnt[i]<<endl;
    }
    return 0;
}