#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
int main(){
    int N; cin>>N;
    int P[N];
    forin(P, N);
    int ans=0;
    int tmp[3];
    for(int i=1; i<N-1; i++){
        tmp[0]=P[i-1];
        tmp[1]=P[i];
        tmp[2]=P[i+1];
        sort(tmp, tmp+3);
        if(tmp[1]==P[i]) ans++;
    }
    cout<<ans<<endl;
}
