#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
int ctoi(char c){return (int)c-(int)'a';}
int main() {
    string s,t; cin>>s>>t;
    vector<vi> char_pos(26);
    for (int i = 0; i < s.size(); i++){
        char_pos[ctoi(s[i])].push_back(i);
    }
    vi count(26,0);
    vi reset=count;
    int pos=-1;
    ll ans=0;
    for (int i = 0; i < t.size(); i++){
        int ci=ctoi(t[i]);
        if(char_pos[ci].size()==0){
            cout<<-1<<endl;
            return 0;
        }
        while(1){

            count[ci]++;
            if(count[ci]-1==char_pos[ci].size()){
                ans+=s.size()-1-pos;
                ans+=char_pos[ci][0]+1;
                pos=char_pos[ci][0];
                count=reset;
                count[ci]=1;
                break;
            }
            if(char_pos[ci][count[ci]-1]>pos){
                ans+=char_pos[ci][count[ci]-1]-pos;
                pos=char_pos[ci][count[ci]-1];
                break;
            }
        }
    }
    cout<<ans<<endl;
}