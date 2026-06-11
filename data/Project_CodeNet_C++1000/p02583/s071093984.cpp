#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int l[n];
    for(int i = 0; i < n; i++)
        cin >> l[i];

    sort(l, l + n);

    int cnt = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(l[i] != l[j] && l[j] != l[k] && l[k] != l[i] && (l[i] + l[j] > l[k]))
                    cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}