#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;

    vector<vector<string>> lunlun(12);
    for(int i=1; i<=9; i++){
        string s = " ";
        s[0] = '0' + i;
        lunlun[0].push_back(s);
        //cout << s << endl;
    }
    for(int i=1; i<12; i++){
        for(string l : lunlun[i-1]){
            string s = " ", t = " ", u = " ";
            s[0] = l[i-1] - 1;
            t[0] = l[i-1];
            u[0] = l[i-1] + 1;
            if(l[i-1] != '0') lunlun[i].push_back(l+s);
            lunlun[i].push_back(l+t);
            if(l[i-1] != '9') lunlun[i].push_back(l+u);
        }
    }
    vector<string> ans;
    for(int i=0; i<12; i++){
        for(string l : lunlun[i]){
            ans.push_back(l);
            //if(i <= 1) cout << l << " ";
        }
    }
    cout << ans[k-1] << endl;
    return 0;
}