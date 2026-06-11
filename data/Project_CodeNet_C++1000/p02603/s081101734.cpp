#include <iostream>

using namespace std;
const int N = 100;
int n;
int a[N];
long long dp[N];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long gold = 1000 , promissory_note = 0 , val_ed = 1e18;
    int sell = 0 , buy = 1;
    long long ans = 1000;
    for (int i = 1; i <= n; i++){
        if (val_ed > a[i]){
            sell = 0;
            if (buy >= 1) gold = gold + promissory_note * val_ed;
            promissory_note = gold / a[i];
            gold = gold % a[i];
            val_ed = a[i];
            buy++;
            dp[i] = gold;
        }
        else{
            buy = 0;
            if (sell >= 1){
                promissory_note = gold / val_ed;
                gold -= promissory_note * val_ed;
            }
            gold = gold + promissory_note * a[i];
            promissory_note = 0;
            val_ed = a[i];
            sell++;
            dp[i] = gold;
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
}