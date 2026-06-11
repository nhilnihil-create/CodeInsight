#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    string s, t;
    int i=0, j=0;

    cin >> s >> t;

    int mini=t.size();

    for(i=0; i<(s.size()-t.size()+1); i++){
        int k=i;
        int cnt=0;
        for(j=0; j<t.size(); j++){
            if(t[j]!=s[k]){
                cnt++;
            }
            k++;
        }
        if(cnt<mini){
            mini = cnt;
        }
    }

    cout << mini << endl;
    return 0;
}
