    #include<bits/stdc++.h>

    using namespace std;
    typedef long long ll;

    #define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #define mp make_pair
    #define pb push_back
    #define lp(i,s,f) for(ll i = s; i < ll(f); i++)
    #define inF freopen("input.in", "r", stdin);
    #define outF freopen("output.in", "w", stdout);
    #define endl '\n'
    #define MOD 1000000007
    #define mm(arr) memset(arr, 0, sizeof(arr))
    #define int ll

    int32_t main(){
        FAST
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                cout << 0;
                return 0;
            }
        }
        int res = 1;
        for(int i = 0; i < n; i++){
            if(1000000000000000000LL/res >= arr[i]){
                res *= arr[i];
            }
            else{
                cout << -1;
                return 0;
            }
        }
        cout << res;
        return 0;
    }
