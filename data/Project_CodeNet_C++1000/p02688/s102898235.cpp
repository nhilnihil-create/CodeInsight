#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i=0; i<n; i++){
        arr[i]=0;
    }

    for (int i=0; i<k; i++){
        int n1;
        cin >> n1;

        for (int j=0; j<n1; j++){
            int x;
            cin >> x;
            arr[x-1]++;
        }
    }

    int ans=0;

    for (int i=0; i<n; i++){
        if (arr[i]==0){
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
