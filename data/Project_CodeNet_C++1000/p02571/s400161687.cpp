#include <bits/stdc++.h>
#define ll long long
using namespace std;

void testcase(){
    string s,t;
    cin >> s >> t;
    int ns=s.length();
    int nt=t.length();
    int mx=0;
    for(int i=0;i<ns-nt+1;i++){
        int c=0;
        for(int j=0;j<nt;j++){
            if(s[i+j]==t[j])
                c++;
        }
        mx=max(mx,c);
    }
    cout << nt-mx;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1;
  //  cin >> q;
    while(q--){
    testcase();
    }
    return 0;
}

