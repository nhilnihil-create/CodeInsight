#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N, M;  cin >> N >> M;
    string S;  cin >> S;
    
    vector<int> ans;
    for(int i=N; i>=0; i--){
        if(i - M <= 0){
            ans.push_back(i);
            i = 0;
        }else{
            for(int j=i-M; j<=i-1; j++){
                if(S[j] == '0'){
                    // cout << i << " -> " << j << endl;
                    ans.push_back(i-j);
                    i = j + 1;
                    break;
                }
                if(j == i-1){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }cout << endl;
}
