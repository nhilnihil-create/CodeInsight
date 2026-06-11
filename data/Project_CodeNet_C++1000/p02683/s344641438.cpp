#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

void textIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}

bool Check(int n, int pos){return (bool)(n&(1<<pos));}
long long Set(int n, int pos){return n=n|(1<<pos);}
int Reset(int n, int pos){return n=n&~(1<<pos);}

long long n, m, x, ans = LONG_LONG_MAX;

vector<long long> cost(12);
vector<vector<long long>> arr(12, vector<long long> (12));


pair<bool, long long> getSol(int mask){
    long long ret = 0;

    for(int i=0;i<n;i++){
        if(Check(mask, i) == true){
            ret+=cost[i];
        }
    }
    for(int i=0;i<m;i++){
        long long sum = 0;
        for(int j=0;j<n;j++){
            if(Check(mask, j) == true){
                sum+=arr[j][i];
            }
        }
        if(sum < x){
            return {false, 0};
        }
    }
    return {true, ret};
}

void solve(int ind, int mask){
    if(ind == n){
        pair<bool, long long> p = getSol(mask);
        if(p.first == true){
            ans = min(ans, p.second);
        }
        return;
    }
    solve(ind+1, Set(mask, ind));
    solve(ind+1, mask);
}


int main()
{
    textIO();
    fastIO();


    cin >> n >> m >> x;

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(j==0){
                cin >> cost[i];
            }
            else{
                cin >> arr[i][j-1];
            }
        }
    }


    solve(0, 0);

    if(ans != LONG_LONG_MAX){
        cout << ans << '\n';
    }
    else{
        cout << -1 << '\n';
    }


    return 0;
}
