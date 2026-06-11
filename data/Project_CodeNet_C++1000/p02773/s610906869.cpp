#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;

    map<string, int> dic;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;

        dic[s]++;
    }

    vector<pair<int, string>> S;
    for(auto a : dic){
        S.push_back({a.second, a.first});

    }

    sort(S.begin(), S.end());
 
    //cout<<"-------------answer-------------"<<endl;
    
    int max_num = S[S.size()-1].first;
    for(int i=0; i<S.size(); i++){
        if(max_num > S[i].first){

            continue;
        }

        cout<<S[i].second<<endl;
    }
    
    return 0;
}