#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

long long n,k,c;
string s;
vector<int>getWorkday_L(){
    int now=0;
    vector<int>ret;
    for(int i=0;i<n;i++){
        if(now<=0 && s[i]!='x'){
            ret.push_back(i+1);
            now=c;
        }
        else{
            now--;
        }
    }
    return ret;
}
vector<int>getWorkday_R(){
    int now=0;
    int num=k;
    vector<int>ret;
    for(int i=n-1;i>-1;i--){
        if(now<=0 && s[i]!='x'){
            ret.insert(ret.begin(),i+1);
            now=c;
        }
        else{
            now--;
        }
    }
    return ret;
}
//status unsolved
int main(){
    
    cin>>n>>k>>c;
    cin>>s;
    
    vector<int>w=getWorkday_L();
    vector<int>R=getWorkday_R();
    
    if(w.size()>k){
        return 0;
    }
    else{
        
        rep(i,w.size()){
            if(R[i]==w[i]){
                cout<<R[i]<<endl;
            }
        }

    }
    return 0;

}
/*


*/
