#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long count=0;
    long long val;
    long long min_val = N;
    for(int i=0; i<N; i++){
        cin >> val;
        if(val <= min_val){
            count += 1;
            min_val = val;
        }
    }

    cout << count << endl;
    return 0;


}