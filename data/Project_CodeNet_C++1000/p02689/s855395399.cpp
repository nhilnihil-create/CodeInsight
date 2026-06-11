#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>> n >> m;
    
    vector<int> h(n);

    for(int i=0; i<n; i++){
        cin>>h[i];
    }

    vector<int> good(n, 0);
    for(int i=0; i<m; i++){
        int a, b;
        cin>> a >> b;
        a--;
        b--;
        good[a] = max(good[a], h[b]);
        good[b] = max(good[b], h[a]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(h[i] > good[i]){
            cnt++;
        }
    }
    cout<< cnt <<endl;
    return 0;
}