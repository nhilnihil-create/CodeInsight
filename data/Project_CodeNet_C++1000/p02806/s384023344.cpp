#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<string, int>> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i].first >> songs[i].second;
    }
    reverse(songs.begin(), songs.end());
    string x; cin >> x;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(songs[i].first == x){
            break;
        }
        sum += songs[i].second;
    }
    cout << sum << '\n';
    return 0;
}
