#include<iostream>
#include<vector>
#include<numeric>
#include<string>
using namespace std;

int main(){
    int n,k,r,s,p;
    string t;
    cin>>n>>k;
    cin>>r>>s>>p;
    cin>>t;

    vector<int> score(n,0);
    for(int i=0;i<k;++i){
        int temp;
        if(t[i]=='r') temp=p;
        else if(t[i]=='s') temp=r;
        else temp=s;
        score[i]=temp;
    }

    for(int i=k;i<n;++i){
        if(t[i]!=t[i-k]){
            int temp;
            if(t[i]=='r') temp=p;
            else if(t[i]=='s') temp=r;
            else temp=s;
            score[i]=temp;
            continue;
        }

        if(score[i-k]==0){
            int temp;
            if(t[i]=='r') temp=p;
            else if(t[i]=='s') temp=r;
            else temp=s;
            score[i]=temp;
        }
    }

    long long ans=accumulate(score.begin(),score.end(),0);
    cout<<ans<<endl;
}