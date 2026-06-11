#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    bool flag[101][101];

    if((n-1)*(n-2)/2 < k){
        cout << -1 << endl;
        return 0;
    }

    rep(i,101){
        rep(j,101){
            flag[i][j] = false;
        }
    }

    reps(i,1,n){
        flag[0][i] = true;
    }
    int cnt = (n-2)*(n-1)/2;
    int edge = n-1;

    rep(i,n){
        reps(j,i+1,n){
            if(!flag[i][j]){
                flag[i][j]=true;
                cnt--;
                edge++;
            }
            if(cnt == k){
                break;
            }
        }
        if(cnt == k){
            break;
        }
    } 
    cout << edge << endl;

    rep(i,101){
        rep(j,101){
            if(flag[i][j]){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }

    return 0;
}