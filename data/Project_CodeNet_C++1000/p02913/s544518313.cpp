#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using ll=long long;
void construct_sa(string S, vi &sa){
    int N=S.size();
    vi rank(N+1);
    for (int i = 0; i <= N; i++){
        sa[i]=i;
        rank[i]=i<N ? S[i] : -1;
    }
    vi tmp(N+1);
    for (int k = 1; k <=N ; k*=2){
        auto compare_sa=[&rank,k,N](auto const& l, auto const& r){
            if(rank[l]!=rank[r])return rank[l]<rank[r];
            else{
                int ri= l+k<=N ? rank[l+k] : -1;
                int rj= r+k<=N ? rank[r+k] : -1;
                return ri<rj;
            }
        };
        sort(sa.begin(),sa.begin()+N+1,compare_sa);
        tmp[sa[0]]=0;
        for (int i = 1; i <=N ; i++){
            tmp[sa[i]]=tmp[sa[i-1]] + (compare_sa(sa[i-1],sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <=N ; i++){
            rank[i]=tmp[i];
        }
    }
}
void construct_lcp(string S, vi &sa, vi &lcp){
    int N=S.size();
    vi rank(N+1);
    for (int i = 0; i <=N ; i++)rank[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for (int i = 0; i < N; i++){
        int j=sa[rank[i]-1];
        if(h>0)h--;
        for (; j+h<N && i+h<N; h++){
            if(S[j+h]!=S[i+h])break;
        }
        lcp[rank[i]-1]=h;
    }
}
int main() {
    int N; cin>>N;
    string S; cin>>S;
    vi sa(N+1),lcp(N+1);
    construct_sa(S,sa);
    construct_lcp(S,sa,lcp);
    int ans=0;
    for (int i = 0; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            ans=max(ans,min(min(lcp[i],abs(sa[i]-sa[j])),N/2));
            if(lcp[i]>lcp[j])break;
        }
    }
    cout<<ans<<endl;
}