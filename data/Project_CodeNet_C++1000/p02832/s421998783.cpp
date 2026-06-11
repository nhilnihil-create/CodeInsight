#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    
    int target = 1;
    for(int i=0; i<N; i++){
        if(target == a[i]){
            target += 1;
        }
    }

    int count = N - (target-1);
    if(target == 1){
        cout << -1 << endl;
    }else{
        cout << count << endl;
    }
    return 0;
    
}