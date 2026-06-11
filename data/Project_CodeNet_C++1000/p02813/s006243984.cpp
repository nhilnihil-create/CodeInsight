#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int a[10], b[10], per[10];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        per[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans_a = 1;
    do{
        bool found = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != per[i]){
                found = 1;
                break;
            }
        }
        if(!found) break;
        ans_a++;
    }while(next_permutation(per, per + n));
    sort(per, per + n);
    int ans_b = 1;
    do{
        bool found = 0;
        for(int i = 0; i < n; i++){
            if(b[i] != per[i]){
                found = 1;
                break;
            }
        }
        if(!found) break;
        ans_b++;
    }while(next_permutation(per, per + n));
    cout << abs(ans_a - ans_b);

    return 0;
}
