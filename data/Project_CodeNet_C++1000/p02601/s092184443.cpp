#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int R,G,B,K;cin>>R>>G>>B>>K;
    int q=100,r=100;
    for(int i=0;i<=K;i++){
        if(R<G*(1<<i)){
            q=i;
            break;
        }
    }
    for(int i=0;i<=K;i++){
        if(G*(1<<q)<B*(1<<i)){
            r=i;
            break;
        }
    }
    if(q+r<=K)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}