#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    long long int ans = 0;
    cin >> n;
    vector<int>step(n);

    for(int i = 0; i < n; i++){
        cin >> step[i];
    }

    int max_step = 0;

    for(int i = 0; i < n; i++){
        max_step = max(max_step,step[i]);
        
        ans += max_step-step[i];
    }
    cout << ans << endl;
}