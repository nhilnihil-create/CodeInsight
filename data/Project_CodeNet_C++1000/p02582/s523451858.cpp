#include <bits/stdc++.h>
using namespace std;

int main(){ //ABC 175
    /* A */
    string s;
    cin >> s;
    int ans=0,cnt=0;
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='R'){
            cnt++;
            if(ans<cnt)ans=cnt;
        }else{cnt=0;}
    }
    cout << ans << endl;

    /* B
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans += s.at(i) - '0';
    }
    cout << ((ans%9==0)? "Yes":"No") << endl;*/

    /* C 
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    int64_t ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            ans += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;*/


    return 0;
}