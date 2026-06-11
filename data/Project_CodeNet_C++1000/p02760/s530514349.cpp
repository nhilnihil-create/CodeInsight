/*
      author  : nishi5451
      created : 15.08.2020 14:17:41
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<vector<int>> v(4,vector<int>(4));
    vector<vector<bool>> bin(4,vector<bool>(4,false));
    for(int i=1; i<=3; i++) 
        for(int j=1; j<=3; j++) 
            cin >> v[i][j];
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int b;
        cin >> b;
        for(int j=1; j<=3; j++) 
            for(int k=1; k<=3; k++) 
                if(v[j][k]==b)
                    bin[j][k]=true;
    }
   
    bool ans = false;
    for(int i=1; i<=3; i++){
        bool bingo = true;
        for(int j=1; j<=3; j++){
            if(bin[i][j] == false) bingo = false;
        }
        if(bingo==true) ans = true;
    }
    for(int i=1; i<=3; i++){
        bool bingo = true;
        for(int j=1; j<=3; j++){
            if(bin[j][i] == false) bingo = false;
        }
        if(bingo==true) ans = true;
    }
    
    if(bin[1][1]&&bin[2][2]&&bin[3][3]) ans = true;
    if(bin[1][3]&&bin[2][2]&&bin[3][1]) ans = true;
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}