#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    string S; cin >> S;
    string T; cin>> T;
    int cnt = 0;
    if(S[0] == T[0]) cnt++;
    if(S[1] == T[1]) cnt++;
    if(S[2] == T[2]) cnt++;

    cout<< cnt << endl;
}
