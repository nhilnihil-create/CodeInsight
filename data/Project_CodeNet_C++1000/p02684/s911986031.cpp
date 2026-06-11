#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int cur_pos[N+5]; 
int tele[N+5];
ll pred[N+5];


int main(){
    AC
    int n;
    ll k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>tele[i];
        tele[i]--;
    }
    memset(pred, -1, sizeof(pred));

    cur_pos[0] = 0;
    pred[0] = 0;
    for(ll i = 1; i<=k; i++){
        cur_pos[i] = tele[cur_pos[i-1]];
        if(pred[cur_pos[i]]!=-1){
            // city already visited
            ll cycle_len = i-pred[cur_pos[i]];
            ll last_steps = (k-i)%cycle_len;
            ll last_pos = cur_pos[pred[cur_pos[i]]+last_steps];
            cout<<last_pos+1<<endl;
            return 0;
        }
        else
            pred[cur_pos[i]] = i;
    }
    cout<<cur_pos[k]+1<<endl;
}