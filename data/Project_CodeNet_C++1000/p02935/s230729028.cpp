#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N; cin>>N;
    vi v(N);
    for (int i = 0; i < N; i++)cin>>v[i];
    sort(v.begin(),v.end());
    double ans=v[0];
    for (int i = 0; i < N-1; i++){
        ans=(ans+v[i+1])/2.0;
    }
    printf("%.6f\n",ans);
}