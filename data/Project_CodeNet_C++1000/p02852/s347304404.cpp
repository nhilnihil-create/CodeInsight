#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> walk;

    int now = n;
    while(now > m){
        for(int i = m; i > 0; i--){
            if (s[now-i] == '0'){
                now = now-i;
                walk.push_back(i);
                break;
            }
            if (i == 1){
                cout << -1 << endl;
                return 0;
            }
        } 
    }
    walk.push_back(now);
    for(int i = walk.size()-1; i >= 0; i--){
        cout << walk[i];
        if (i > 0)cout << " ";
    }
    cout << endl;
    return 0;
}