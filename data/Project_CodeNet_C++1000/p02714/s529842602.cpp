#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N; string S;
void input()
{
    cin>>N>>S;
}

void solve()
{
    vi R_cnt(N,0),G_cnt(N,0),B_cnt(N,0);
    if(S[0]=='R') R_cnt[0]=1;
    else if(S[0]=='G') G_cnt[0]=1;
    else if(S[0]=='B') B_cnt[0]=1;
    for(int i=1;i<N;++i){
        R_cnt[i]=R_cnt[i-1];G_cnt[i]=G_cnt[i-1];B_cnt[i]=B_cnt[i-1];
        if(S[i]=='R') R_cnt[i]++;
        else if(S[i]=='G') G_cnt[i]++;
        else if(S[i]=='B') B_cnt[i]++;
    }
    ll ans=0;
    for(int i=0;i<N-2;++i){
        for(int j=i+1;j<N-1;++j){
            if((S[i]=='R' && S[j]=='G') || (S[j]=='R' && S[i]=='G')){
                ans+=B_cnt[N-1]-B_cnt[j];
                if(j-i+j<N && S[j-i+j]=='B') --ans;
            }
            else if((S[i]=='G' && S[j]=='B') || (S[j]=='G' && S[i]=='B')){
                ans+=R_cnt[N-1]-R_cnt[j];
                if(j-i+j<N && S[j-i+j]=='R') --ans;
            }
            else if((S[i]=='R' && S[j]=='B') || (S[j]=='R' && S[i]=='B')){
                ans+=G_cnt[N-1]-G_cnt[j];
                if(j-i+j<N && S[j-i+j]=='G') --ans;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}