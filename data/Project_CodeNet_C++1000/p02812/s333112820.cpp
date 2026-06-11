#include <bits/stdc++.h>

using namespace std;

int main() {

    int n ;
    cin>>n;
    string s;
    cin>>s;
    int idx;

    idx = s.find("ABC");

    int ans=0;

    while(idx!=-1){
        ans++;
        idx = s.find("ABC",idx+1);
    }

    cout<<ans<<endl;

    return 0;
}
