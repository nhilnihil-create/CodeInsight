#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void testCase(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> mp;
    int pair = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                if(mp[j] == 1){
                    pair = 0;
                    break;
                }
                if(j != 1 && mp[j] == 0){
                    mp[j] = 1;
                }
                if(j * j != a[i] && mp[a[i] / j] == 1){
                    pair = 0;
                    break;
                }
                if(j * j != a[i]){
                    mp[a[i] / j] = 1;
                }
            }
        }
        if(pair == 0){
            break;
        }
    }

    if(pair){
        cout << "pairwise coprime" << endl;
    } else{
        int gd = a[0];
        for(int i = 0; i < n; i++){
            gd = gcd(gd, a[i]);
        }
        if(gd == 1){
            cout << "setwise coprime" << endl;
        } else{
            cout << "not coprime" << endl;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // int t; cin >> t;
    while(t--)
        testCase();
    
    return 0;
}