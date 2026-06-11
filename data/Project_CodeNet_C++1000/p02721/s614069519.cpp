#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    vector<int> ve;
    for(int i = 0 ; i < s.size() ; i++){
        if(ve.size() == k)break;
        if(s[i]=='o'){
            ve.push_back(i);
            i += c;
        }
    }
    vector<int> ans;
//    for(int i = 0 ; i < ve.size() ; i++){
//        cout << ve[i] << ' ' ;
//    }
//    cout << endl;
    int now = n-1;
    for(int i = ve.size() - 1 ; i >= 0 ; i--){
        while(s[now] != 'o'){
            now--;
        }
//        cout << ve[i] << ' ' << now << endl;
        if(now != ve[i]){
            now -= c + 1;
        }else{
            ans.push_back(ve[i]);
            now -= c + 1;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] + 1 << endl;
    }
}
