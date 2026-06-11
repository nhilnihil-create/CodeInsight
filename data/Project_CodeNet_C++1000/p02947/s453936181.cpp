#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    string inp;
    vector<string> s;

    for(int i = 0; i < n; i++){
        cin >> inp;
        sort(inp.begin(), inp.end());
        s.push_back(inp);
    }

    sort(s.begin(), s.end());
    long long int ans = 0, cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i-1] == s[i]){
            cnt++;
        }else{
            if(cnt > 0){
                ans += cnt*(cnt-1)/2;
                cnt = 1;
            }
        }
    }
    ans += cnt*(cnt-1)/2;
    
    cout << (ans == n ? 0 : ans)<< endl;
    return 0;
}