#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nr = 0;
    vector<int> ad;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            nr++;
            ad.push_back(i);
        }
    }
    for(int i = 0; i < nr; i++){
        if(s[i] == 'W'){
            s[i] = 'R';
            int a = ad.back();
            ad.pop_back();
            s[a] = 'W';
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}