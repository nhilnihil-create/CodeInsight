#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int N,X;
    cin >> N >> X;
    vector<int> L(N);
    for(int i=0;i<N;i++) cin >> L.at(i);
    int count=1;
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=L.at(i);
        if(sum>X) break;
        count++;
    }
    cout << count << endl;
}