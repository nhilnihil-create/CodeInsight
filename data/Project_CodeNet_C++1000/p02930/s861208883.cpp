#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    int N;cin>>N;
    N--;
    int ans,maxi;
    for(int i=29;i>=0;i--){
        if(N&(1<<i)){
            ans=i;
            maxi=(1<<(i+1));
            break;
        }
    }
    
    vector<vector<int>> S(maxi,vector<int>(maxi,0));
    
    for(int k=0;k<=ans;k++){
        for(int i=0;i<maxi;i++){
            for(int j=0;j<maxi;j++){
                if((i&(1<<k))!=(j&(1<<k))) S[i][j]=k+1;
            }
        }
    }
    
    for(int i=0;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    
}



