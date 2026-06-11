#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1LL << 60;
ll MOD = 1e9+7;

int main() {

    int K; cin>>K;
    string S; cin>>S;

    if(S.size()<=K) cout<<S<<endl;
    else{
        for (int i = 0; i < K; ++i) {
            cout<<S[i];
        }
        cout<<"..."<<endl;
    }

}