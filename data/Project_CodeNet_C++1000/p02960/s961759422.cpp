#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N = pow(10,9) + 7;

int main(){
    string s;
    cin >> s;
    int n = (int)s.size();
    reverse(s.begin(), s.end());
    int keta_mod[6] = {1, 10, 9, 12, 3, 4};
    vector<vector<ll>> dp(n+1,vector<ll>(13,0));
    dp.at(0).at(0) = 1;
    for(int i=1; i<=n; i++){
        //下i桁まで使う
        if(s.at(i-1) != '?'){
            int k = s.at(i-1) - '0';
            int plus = k * keta_mod[(i-1)%6];
            for(int j=0; j<13; j++){
                if(dp.at(i-1).at(j)==0) continue;
                int t = (j+plus)%13;
                dp.at(i).at(t) = (dp.at(i).at(t)+dp.at(i-1).at(j))%N;
            }
        }
        else{
            // '?'だった時
            for(int k=0; k<10; k++){
                int plus = k * keta_mod[(i-1)%6];
                for(int j=0; j<13; j++){
                    if(dp.at(i-1).at(j)==0) continue;
                    int t = (j+plus)%13;
                    dp.at(i).at(t) = (dp.at(i).at(t)+dp.at(i-1).at(j))%N;
                }
            }
        }
    }
    /*
    for(int i=0; i<n+1; i++){
        for(int j=0; j<13; j++){
            cout << dp.at(i).at(j) << ' ';
        }
        cout << endl;
        
    }
    */
    
    cout << dp.at(n).at(5) << endl;
}
