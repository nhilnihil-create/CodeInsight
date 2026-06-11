#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, D;
    cin >> N >> D;
    int sum =0;
    int count =0;

    for(int i=0; sum<N; i++){
        sum += 2*D+1;
        count++;
    }
    cout << count << endl;
}