#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;
const double PI = 3.141592653589793238460;
const int INF = 1e9+5;

long long int x;
int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);    

    cin >> n >> x;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    if(a[1]==1){
        cout<<1;
        return 0;
    }

    vector<bool> vis(n+1);

    int start = 1;
    int count = 0;
    while(true){
        if(vis[start]==true) break;
        vis[start]=true;
        start = a[start];
        count++;
    }

    int temp=start;
    int cycle=0;
    while(temp!=start || cycle==0){
        temp = a[temp];
        cycle++;
    }

    if(x<=(count-cycle)){
        temp = 1;
        while(x>0){
            temp=a[temp];
            x--;
        }
        cout<<temp;
        return 0;
    }

    x -= (count-cycle);
    x = x%cycle;

    while(x>0 && cycle!=1){
        start=a[start];
        x--;
    }

    cout<<start;
    return 0;
}
