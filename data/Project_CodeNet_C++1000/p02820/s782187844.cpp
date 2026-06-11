#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N,K; cin>>N>>K;
    int R,S,P; cin>>R>>S>>P;
    string T;cin>>T;
    vi sum(3,0);
    map<char,int> ctoi;
    ctoi['r']=0;ctoi['s']=1;ctoi['p']=2;
    for (int i = 0; i < K; i++)sum[ctoi[T[i]]]++;
    vector<bool> lose(N,false);
    for (int i = K; i < N; i++){
        if(T[i]==T[i-K] && !lose[i-K])lose[i]=true;
        else{
            sum[ctoi[T[i]]]++;
            lose[i]=false;
        }
    }
    cout<<sum[0]*P+sum[1]*R+sum[2]*S<<endl;
}