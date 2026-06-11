#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
int main(){
    int N; cin>>N;
    int d[N];
    forin(d, N); sort(d, d+N);
    cout<<d[N/2]-d[N/2-1]<<endl;
}
