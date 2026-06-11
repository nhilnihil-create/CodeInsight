#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    map<string,long long>mp;
    for(int i=0; i<n; i++){
        cin >> s;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    long long ans=0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        /*
        std::cout << "key = " << itr->first
                  << ", val = " << itr->second << "\n";   
        */
        if(itr->second==2) ans++;
        if(itr->second>2){
            long long a = itr->second;
            if(a%2==0){
                ans += a/2*(a-1);
            }else{
                ans += (a-1)/2*a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}