#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

using namespace std;

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;i++)
using ll = long long;
using ull = unsigned long long;
using llv = vector<long long>;


int main(void){
    ll n;
    cin >> n;
    vector<string> s (n);
    rep(i,n) cin >> s[i];
    sort(s.begin(),s.end());
    
    vector<string> result (0);
    string current_str = "";
    
    ll count = 0;
    ll max_count = 0;
    for(int i = 0;i < n;i++){
        if (current_str == s[i]){
            count++;
        } else {
            if(count > max_count){
                result = vector<string> (0);
                result.push_back(current_str);
                max_count = count;
            } else if (count == max_count){
                result.push_back(current_str);
            } 
            current_str = s[i];
            count = 1;
        }
    }

    if(count > max_count){
        result = vector<string> (0);
        result.push_back(current_str);
        max_count = count;
    } else if (count == max_count){
        result.push_back(current_str);
    }

    for(auto &str : result){
        cout << str << endl;
    }
}