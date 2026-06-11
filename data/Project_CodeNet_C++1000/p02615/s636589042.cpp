#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector< int > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //フレンドリーさが最大順に並べる
    sort(a.begin(),a.end(),greater<int>());
    queue<int> q;
    q.push(a[0]);
    long long ans = 0;
    for(int i=1;i<n;i++){
        int f = q.front();
        q.pop();
        ans += f;
        q.push(a[i]);
        q.push(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}