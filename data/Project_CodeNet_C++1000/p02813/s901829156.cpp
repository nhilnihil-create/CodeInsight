#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353a
#define pi acos(-1)
#define all(v) v.begin(),v.end()

bool check(vector<int>a,vector<int>b,int N){
    bool flag=0;
    for(int i=0;i<N;i++){
        if(a.at(i)!=b.at(i)){
            flag=1;
            break;
        }
    }
    return flag;
}
int main(){
    int N;
    cin>>N;
    vector<int>P(N);
    vector<int>Q(N);
    vector<int>R(N);
    int pCount=0;
    int qCount=0;
    int count=0;
    for(int i=0;i<N;i++){
        cin>>P.at(i);
    }
    for(int i=0;i<N;i++){
        cin>>Q.at(i);
    }
    for(int i=0;i<N;i++){
        R.at(i)=i+1;
    }
    do{
        for(int i=0;i<N;i++){
            if(check(P,R,N)==0){
                pCount=count;
            }
            if(check(Q,R,N)==0){
                qCount=count;
            }
        }
        count++;
    }while(next_permutation(R.begin(),R.end()));

    cout<<abs(pCount-qCount)<<endl;
}
