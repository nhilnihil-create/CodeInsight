#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> memo;
    for(int i = 1; i <= n; i++){
        if(memo.count(i-a[i])) memo[i-a[i]]++;
        else memo[i-a[i]] = 1;
    }

    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        if(memo.count(i-a[i])){
            if(memo[i-a[i]] == 1) memo.erase(i-a[i]);
            else memo[i-a[i]]--;
        }
        if(memo.count(i+a[i])){
            ans += memo[i+a[i]];
        }
    }
    cout << ans << endl;
    return 0;
}