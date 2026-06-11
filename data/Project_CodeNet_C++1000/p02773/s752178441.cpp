#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;
    cin>>N;
    map<string,int> vote;
    int max_vote=0;
    for (int i = 0; i < N; i++){
        string s;
        cin>>s;
        vote[s]++;
        max_vote=max(max_vote,vote[s]);
    }
    vector<string> ans;
    for(pair<string,int> p:vote){
        string key=p.first;
        int val=p.second;
        if(val==max_vote){
            ans.push_back(key);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto name:ans){
        cout<<name<<endl;
    }
}