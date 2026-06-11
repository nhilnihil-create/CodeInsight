#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;;
    cin >> N;
    vector<string> S(N);
    map<string,int> data;
    
    for (int i=0;i<N;i++) {
        cin >> S[i];
        data[S[i]] = i;
    }
    
    cout << data.size() << endl;
}
