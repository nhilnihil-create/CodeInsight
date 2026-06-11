//hail to jwalaji
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   // cout<<"good 1: "<<endl;
    vector<int> arr[1000002];
    for(lli i=2;i<1000002;i++){
        if(arr[i].size()==0){
                lli k=i;
            while(k<1000002){
                arr[k].push_back(i);
                k+=i;
            }
        }
    }
    // cout<<"good 2: "<<endl;
    vector<lli> coun(1000002,0);
    lli n,maxa=0;
    cin>>n;
    for(lli i=0;i<n;i++){
        lli a;
        cin>>a;
        for(auto &k:arr[a]){
            coun[k]++;
            if(coun[k]>maxa){
                maxa=coun[k];
            }
        }
    }
    if(maxa>=n){
        cout<<"not coprime"<<endl;
    }
    else if(maxa==1||maxa==0){
        cout<<"pairwise coprime"<<endl;
    }
    else{
        cout<<"setwise coprime"<<endl;
    }
return 0;
}
