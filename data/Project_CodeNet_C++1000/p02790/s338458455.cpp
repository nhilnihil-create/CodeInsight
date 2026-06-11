#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    int a, b; cin>> a >> b;
    for(int i=0; i<max(a, b); i++) cout<< min(a, b);
    cout<< endl;
}
