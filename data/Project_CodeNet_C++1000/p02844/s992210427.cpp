#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000


int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int list[1001];
    rep(i,1001){
        list[i] = 0;
    }
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                string temp = to_string(i)+to_string(j)+to_string(k);
                int index = 0;
                for(int l = 0; l < n; l++){
                    if(s[l] == temp[index]){
                        index++;
                        if(index == 3){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

}