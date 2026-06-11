#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
#define vi vector<int>
#define ii pair<int,int>
const ll mod=2019;

string S;
ll pot, number, resp, ans;
int i, A;
map<ll,ll> M;

int main(){_
    cin>>S;
    M[0]=1;
    pot =1;
    for(i=S.size()-1;i>=0;i--){
        A=S[i]-'0';
        number=(A*pot+number)%mod;
        pot=(pot*10)%mod;
        ans+=M[number];
        M[number]++;
    }

    cout<<ans<<endl;

    return 0;
}
