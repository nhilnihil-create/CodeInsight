#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    int num[n];
    rep(i, n) num[i]=-1;
    rep(i, m){
        int s, c;
        cin >> s >> c;
        if(num[s-1]!=-1 && num[s-1]!=c){
            cout<<-1<<endl;
            return 0;
        }
        num[s-1]=c;
    }

    if(n==1){
        if(num[0]==-1) cout<<0<<endl;
        else cout<<num[0]<<endl;
        return 0;
    }

    if(num[0]==0){
        cout<<-1<<endl;
        return 0;
    }

    rep(i, n){
        if(i==0){
            if(num[i]==-1) cout<<1;
            else cout<<num[i];
        }else{
            if(num[i]==-1) cout<<0;
            else cout<<num[i];
        }
    }
    cout<<endl;
    return 0;
}