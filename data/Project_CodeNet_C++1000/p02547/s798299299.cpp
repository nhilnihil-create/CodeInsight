#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<int> Da(N);
    vector<int> Db(N);
    for(int i=0;i<N;i++){
        cin>>Da.at(i)>>Db.at(i);
    }
    int tmp = 0;
    vector<int> ans(N,0);
    if(Da.at(0)==Db.at(0)){
        ans.at(0)=1;
    }
    for(int i=1;i<N;i++){
        if(Da.at(i)==Db.at(i)){
            ans.at(i)=ans.at(i-1)+1;
        }
        else{
            ans.at(i)=0;
        }
        if(ans.at(i)==3){
            tmp++;
            break;
        }
    }
    if(tmp>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}