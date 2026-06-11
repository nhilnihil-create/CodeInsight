#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


ll N, D, x, y;


void solve(){
    cin >> N >> D;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        

        if (sqrt(x*x+ y*y) <= D)
        {
            count++;
        }
        
    }
    
   cout << count << "\n";
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}