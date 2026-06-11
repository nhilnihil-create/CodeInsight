#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector<string> S(n);

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        S.at(i) = s;

    }

    sort(S.begin(), S.end());

    long cnt = 1,ans=0;
    for(int i=1; i<n; i++){
        if(S.at(i) == S.at(i-1) ){
            cnt++;
            if(i == n-1){
                ans += cnt*(cnt-1)/2 ;
                cnt = 1;
            }
        }else{
            ans += cnt*(cnt-1)/2 ;
            cnt = 1;
        }        
    }
    
    cout << ans << endl;

    return 0;
}
