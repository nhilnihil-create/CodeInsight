#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<char>c(10);
    string s;
    map<string,int>mp;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<10; j++){
            c[j]=s[j];
        }
        sort(c.begin(),c.end());
        for(int j=0; j<10; j++){
            s[j]=c[j];
        }
        mp[s]++;
    }
    long long ans=0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second==2) ans++;
        if(itr->second>2){
            long long a = itr->second;
            if(itr->second==2) ans++;
            else if(itr->second>2){
                ans += a*(a-1)/2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
