#include<bits/stdc++.h>
#define REP(i,x,y) for(ll i=x; i<=y; i++)
#define BIT(t) ((long long 1) << t)
#define PER(i,y,x) for(ll i=y; i>=x; i--)
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
typedef long long ll;

map<int, int> mp;
int tbl[20][(1<<18) + 5];


int main(){
    int n;
    cin >> n;
    REP(i,1,(1 << n)){
        int x;
        cin >> x;
        mp[x]++;
    }
    auto itr = mp.end();
    itr--;
    int cur = 1;
    tbl[n][0] = 1;
    while(1){
        int tmp = itr->second;
        int cnt = 0;
        //cout << tmp << endl;
        PER(i,n,0){
            if(tbl[i][cur-1] >= tmp){
                tbl[i][cur-1] -= tmp;
                if(i>0){
                    tbl[i-1][cur] += tmp;
                }
                tmp = 0;
                //cout << itr->first << " " << i << " " << cur-1 << endl;
            }else {
                tmp -= tbl[i][cur-1];
                if(i>0){
                    tbl[i-1][cur] += tbl[i][cur-1];
                }
                tbl[i][cur-1] = 0;
            }
            if(tmp == 0){
                break;
            }
        }
        if(tmp > 0){
            //cout << itr->first << " " << tmp << endl;
            cout << "No" << endl;
            return 0;
        }
        PER(i,n-1,0){
            tbl[i][cur] += tbl[i+1][cur];
        }
        PER(i,n,0){
            tbl[i][cur] += tbl[i][cur-1];
        }
        //cout << "!" << endl;
        cur++;
        if(itr == mp.begin()){
            break;
        }
        itr--;
    }
    cout << "Yes" << endl;

}
