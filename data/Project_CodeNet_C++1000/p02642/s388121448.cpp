#include<bits/stdc++.h>

using namespace std;

vector<int> cnt(1000000);

int main(){
    int n;cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        cnt[x]++;
    }
    int rj=0;
    for(int i=1;i<=1000000;i++){
        if(cnt[i]){
            if(cnt[i]==1)rj++;
            for(int j=i+i;j<=1000000;j=j+i){
                cnt[j]=0;
            }
        }
    }
    cout <<rj<<endl;
}
