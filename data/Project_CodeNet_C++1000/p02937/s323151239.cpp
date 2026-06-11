#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,t;
    long long int ans=0,now=0;
    cin >> s;
    cin >> t;
    vector<vector<long long int>> num(26);

    for(int i=0;i<s.size();i++){
        num[s[i]-'a'].push_back(i);
    }

    if(num[t[0]-'a'].size()==0){
        cout << -1 << endl;
        return 0;
    }else{
        now = num[t[0]-'a'][0];
    }

    for(int i=1;i<t.size();i++){

        if(num[t[i]-'a'].size()==0){
            cout << -1 << endl;
            return 0;
        }

        if(num[t[i]-'a'].back() < now+1){
            now = num[t[i]-'a'][0];
            ans += s.size();
        }else{
            auto itr = upper_bound(num[t[i]-'a'].begin(),num[t[i]-'a'].end(),now);
            now = *itr;
        }
    }

    cout << ans + now + 1<< endl;
}