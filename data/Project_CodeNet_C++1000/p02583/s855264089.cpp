#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int N;
    cin >> N;
    vector<int> l(N);
    for(int i=0; i<N; i++){
        cin >> l.at(i);
    }

    ll sum=0;

    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            for(int k=j; k<N; k++){
                if(l.at(i)!=l.at(j) && l.at(j)!=l.at(k) && l.at(k)!=l.at(i) && l.at(i)+l.at(j) > l.at(k) && abs(l.at(i)-l.at(j)) < l.at(k)){
                    sum++;
                }
            }
        }
    }

    cout << sum << endl;
}