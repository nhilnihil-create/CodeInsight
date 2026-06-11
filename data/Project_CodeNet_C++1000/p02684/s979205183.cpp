#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

ll n,k;
int a[200001];
int v[200001];

void solve(){

    cin >> n >> k;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp-1;
        v[i] = -1;
    }
    

    int cur = 0;
    int counter = 0;
    v[0]  = 0;

    while(k>0 ){
        cur = a[cur];
        counter++;
        k--;

        if(v[cur] == -1){
            v[cur] = counter;
            
        }
        else{
            ll cyc = counter - v[cur];
            
            k %= cyc;
            for (int i = 0; i < k; i++)
            {
                cur = a[cur];
            }
            
            cout << cur+1 << endl;
            return;
        }

    }

    cout << cur+1 << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}