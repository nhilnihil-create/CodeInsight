#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >>N;
    vector<int> vec(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    double AAA=vec.at(0);
    double sum=AAA;
    for(int i=1;i<N;i++){
        sum=(sum+vec.at(i))/2;
    }
    cout << sum <<endl;


}