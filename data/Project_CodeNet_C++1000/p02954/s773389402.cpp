#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n=s.length();
    vector<int> ans(n,0);
    
    int i=0;
    while(i<n){
        int Rcnt=0;
        while(s[i]=='R'){
            i++;
            Rcnt++;
        }
        int ni=i;
        ans[ni-1]=ans[ni-1]+(Rcnt+1)/2;
        ans[ni]=ans[ni]+Rcnt/2;

        int Lcnt=0;
        while(s[i]=='L'){
            i++;
            Lcnt++;
        }
        ans[ni-1]=ans[ni-1]+Lcnt/2;
        ans[ni]=ans[ni]+(Lcnt+1)/2;
    }
    for (int i = 0; i < n - 1; i++){
        cout << ans.at(i) << " ";
    }
    cout << ans.at(n - 1) << endl;
}

