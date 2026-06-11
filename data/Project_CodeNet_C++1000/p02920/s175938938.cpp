#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>K;
    N=pow(2,K);
    multiset<int> ms;
    for(int i=0;i<N;i++){
        int curr;
        cin>>curr;
        ms.insert(curr*-1);
    }
    vector<int> vals;
    vals.push_back(*ms.begin());
    ms.erase(ms.begin());
    for(int i=0;i<K;i++){
        vector<int> newval;
        for(int j=0;j<vals.size();j++){
            if(ms.upper_bound(vals[j])==ms.end()){
                cout<<"No"<<endl;
                return 0;
            }
            newval.push_back(*ms.upper_bound(vals[j]));
            ms.erase(ms.upper_bound(vals[j]));
            if(ms.empty()){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        //vals.erase(vals.begin(),vals.end());
        for(int j=0;j<newval.size();j++){
            vals.push_back(newval[j]);
        }
        sort(vals.begin(),vals.end());
    }
    cout<<"Yes"<<endl;
    return 0;
    
}