#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i=0;i<N;i++){
        cin >> p.at(i);
    }    
    sort(p.begin(),p.end());
    int a=0;
    for (int i=0;i<K;i++){
            a=a+p.at(i);
    }        
    cout << a << endl;// Your code here!
    
}
