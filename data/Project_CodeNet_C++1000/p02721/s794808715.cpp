#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,c;
    cin>>n>>k>>c;

    string s;
    cin>>s;

    vector <int> v,vv;
    int ans = k;
    int len = s.size();
    for(int i=0; i<len; i++){
        if(s[i]=='o'){
            ans--;
            v.push_back(i+1);
            i += c;

            if(ans == 0) break;
        }
    }

    ans = k;
    for(int i=len-1; i>=0; i--){
        if(s[i]=='o'){
            ans--;
            vv.push_back(i+1);
            i -= c;

            if(ans == 0) break;
        }
    }

    sort(vv.begin(), vv.end());
    for(int i=0; i<k; i++){
        if(v[i]==vv[i]) printf("%d\n",v[i]);
    }

    return 0;
}
