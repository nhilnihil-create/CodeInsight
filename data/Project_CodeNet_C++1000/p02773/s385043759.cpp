#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    int N;
    cin >> N;
    map<string,int> s;
    int val=0;

    for(int i=0;i<N;i++){
        string temp;
        cin>>temp;
        if(s.find(temp)==s.end())s[temp]=0;
        else s[temp]+=1;
    }
    for(auto i=s.begin();i!=s.end();i++){
        val=max(val,i->second);
    };
    vector<string> res;
    for(auto i=s.begin();i!=s.end();i++){
        if(i->second==val)res.emplace_back(i->first);
    };
    sort(res.begin(),res.end());
    for(int i=0;i<(int)res.size();i++)cout<<res[i]<<endl;
    return 0;
}