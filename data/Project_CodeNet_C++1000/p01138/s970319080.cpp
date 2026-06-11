#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int in(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)s[i] -= '0';
    int h = s[0]*10 + s[1];
    int m = s[3]*10 + s[4];
    int ret = s[6]*10 + s[7];
    ret += m * 60 + h * 60*60;
    return ret;
}
int main(){
    int n;
    while(cin >> n, n){
        vector<int> imos(24*60*60+5);
        while(n--){
            imos[in()]++;
            imos[in()]--;
        }
        for(int i = 1; i < 24*60*60+5; i++)imos[i] += imos[i-1];
        int ans = 0;
        for(int i = 0; i < 24*60*60+5; i++)ans = max(ans, imos[i]);
        cout << ans << endl;
    }
}

