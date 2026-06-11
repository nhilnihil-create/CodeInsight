#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){

    double N,sum=0;
    cin >> N;
    vector<double> data(N);
    vector<double> dataaa(N);
    rep(i,N){
        cin >> data.at(i);
        dataaa.at(i)=1/data.at(i);
        sum+=dataaa.at(i);
    }

    cout << setprecision(10) << endl;
    cout << 1/sum << endl;

    
}