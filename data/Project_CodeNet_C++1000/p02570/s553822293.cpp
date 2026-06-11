#include <bits/stdc++.h>
#define ll long long
using namespace std;

void testcase(){
    int d,t,s;
    cin >> d >> t >> s;
    if(t*s>=d)
        cout << "Yes";
    else
        cout << "No";
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

