#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000000;
ll mod = INF;
bool used[maxn+1];
ll k;
ll rest=7;


int main(){

    cin >> k;

    ll idx=1;
    while(true){
        rest=rest%k;
        if(rest==0){
            break;
        }else{
            if(used[rest]){
                idx=-1;
                break;
            }
            used[rest]=true;
        }
        rest=(rest*10+7)%k;
        idx++;
    }

    cout << idx<<endl;
    
    return 0;
}