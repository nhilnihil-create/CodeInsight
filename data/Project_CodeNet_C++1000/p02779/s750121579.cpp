#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("../input.txt","r",stdin);
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        if(A.count(input) == 0) A.insert(input);
        else{
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
}
