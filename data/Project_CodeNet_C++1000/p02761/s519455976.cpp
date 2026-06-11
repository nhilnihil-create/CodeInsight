#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m; cin>>n>>m;
    vector<int> dig(n,-1);
    for(int i=0; i<m; i++){
        int s,c; cin>>s>>c;
        if(n!=1 && s==1 && c==0){
            cout << -1 << endl;
            return 0;
        }
        else{
            if(dig[s-1]==-1) dig[s-1]=c;
            else if(dig[s-1] != c){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dig[i]==-1 && n!=1 && i==0){
            cout << 1;
        }
        else{
            if(dig[i]==-1) cout << 0;
            else cout << dig[i];
        }
    }
    cout << endl;
}