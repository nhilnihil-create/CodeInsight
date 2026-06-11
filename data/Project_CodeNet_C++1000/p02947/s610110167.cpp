#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    std::deque<string> deq(n,"00000000000000000000000000");
    std::map<string, long long int> map;
    for (int i=0;i<n;i++) {
        cin>>s;
        for (int j=0;j<s.size();j++) {
            string tmp=deq[i];
            if (tmp[s[j]-97]=='0') {
                tmp[s[j]-97]='1';
            } else if (tmp[s[j]-97]=='1') {
                tmp[s[j]-97]='2';
            } else if (tmp[s[j]-97]=='2') {
                tmp[s[j]-97]='3';
            } else if (tmp[s[j]-97]=='3') {
                tmp[s[j]-97]='4';
            } else if (tmp[s[j]-97]=='4') {
                tmp[s[j]-97]='5';
            } else if (tmp[s[j]-97]=='5') {
                tmp[s[j]-97]='6';
            } else if (tmp[s[j]-97]=='6') {
                tmp[s[j]-97]='7';
            } else if (tmp[s[j]-97]=='7') {
                tmp[s[j]-97]='8';
            } else if (tmp[s[j]-97]=='8') {
                tmp[s[j]-97]='9';
            } else if (tmp[s[j]-97]=='9') {
                tmp[s[j]-97]='-';
            }
            deq[i]=tmp;
        }
        if (map[deq[i]]==0) {
            map.emplace(deq[i],0);
            map[deq[i]]++;
        } else {
            map[deq[i]]++;
        }
    }
    long long int ans=0;
    for (auto itr=map.begin();itr!=map.end();itr++) {
        ans+=(itr->second*(itr->second-1))/2;
    }
    cout<<ans<<endl;
}