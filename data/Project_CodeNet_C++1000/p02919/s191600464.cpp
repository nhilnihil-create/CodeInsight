#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using LL=long long;
int main() {
    int N; cin>>N;
    vi P(N+1),pos(N+1);//1-indexed
    for (int i = 1; i < N+1; i++){
        cin>>P[i]; 
        pos[P[i]]=i;
    }

    set<int> higher_pos;
    higher_pos.insert(0);
    higher_pos.insert(N+1);
    long long ans=0;
    for (int i = N; i >=1 ; i--){
        higher_pos.insert(pos[i]);
        int l=*prev(higher_pos.find(pos[i]));
        int r=*next(higher_pos.find(pos[i]));
        if(l!=0){
            int ll=*prev(higher_pos.find(l));
            ans+=(LL)i*(l-ll)*(r-pos[i]);
        }
        if(r!=N+1){
            int rr=*next(higher_pos.find(r));
            ans+=(LL)i*(pos[i]-l)*(rr-r);
        }
    }
    cout<<ans<<endl;
}