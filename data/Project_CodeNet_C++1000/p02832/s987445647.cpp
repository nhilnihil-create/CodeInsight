#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int> A;
    cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++)cin >> A[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        if (res+1 == A[i])res++;
    }
    int ans = -1;
    if (res > 0)ans = n- res;
    cout << ans << endl;
    return 0;
}