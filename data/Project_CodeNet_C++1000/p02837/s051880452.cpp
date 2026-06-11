#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pib = pair<int, int>;

bool bitget(int a,int b){
    return a&(1<<b);
}

 
int main (){
    int N;
    cin >> N;
    vector<vector<pib>> A(N);
    for(int i=0;i<N;i++){
        int j;
        cin >> j;
        A[i]=vector<pib>(j);
        for(pib &i:A[i])cin >> i.first >> i.second;
    }
    
    
    
    int maxc=0;
    for(int i=0;i<1<<N;i++){
        int count0=0,cc=0;
        vector<bool> S(N,false);
        vector<vector<int>> T(N);
        vector<vector<int>> F(N);
        for(vector<pib> j:A){
            int count1=0;
            for(pib k:j){
                if(bitget(i,k.first-1)!=k.second)break;
                count1++;
            }
            
            if((count1==j.size())&&bitget(i, cc)){
                S[cc]=true;
                for(pib k:j){
                    if(k.second)T[cc].push_back(k.first-1);
                    else F[cc].push_back(k.first-1);
                }
            }else{
                S[cc]=false;
                if(bitget(i, cc))goto skip;
            }
            cc++;
        }
        cc=0;
        for(int j=0;j<N;j++){
            for(int k=0;k<T[j].size();k++){
                if(!S.at(T[j][k])){
                    S[j]=false;
                    break;
                }
            }
            for(int k=0;k<F[j].size();k++){
                if(S.at(F[j][k])){
                    S[j]=false;
                    break;
                }
            }
            count0+=S[j];
        }
        
        
        maxc=max(maxc,count0);
        
    skip:;
        
    }
    
    cout << maxc << endl;
}
