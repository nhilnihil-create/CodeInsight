#include<bits/stdc++.h>
using namespace std;
#define rep(n,k) for(int i = (int)n;i<k;i++)
using Int =long long int;
using Graph =vector<vector<int>>;
Int cho(Int n){
    return (n-1)*n/2;
}

int main(){

    
    int N;
    cin>>N;
    vector<string>ans(N);
    Int sum=0;
    rep(0,N){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        ans.at(i)=s;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<N;i++){
        string memo = ans[i];
        Int buffer =0;
        do{
            buffer++;
            i++;

        }while(memo==ans[i]);
        i--;
        if(buffer!=1) sum += cho(buffer);
    }
    cout<<sum<<endl;
}
    