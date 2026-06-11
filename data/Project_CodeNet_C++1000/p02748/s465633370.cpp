#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,M;
    cin >> A >> B >> M;
    vector<int> a(A);
    for(int i=0;i<A;i++) cin >> a.at(i);
    vector<int> b(B);
    for(int i=0;i<B;i++) cin >> b.at(i);
    vector<vector<int>> c(M,vector<int>(3));
    for(int i=0;i<M;i++){
        for(int j=0;j<3;j++) cin >> c.at(i).at(j);
    }
    int cost2=10000000;
    for(int i=0;i<M;i++){
        int cost1=a.at(c.at(i).at(0)-1)+b.at(c.at(i).at(1)-1)-c.at(i).at(2);
        cost2=min(cost2,cost1);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << min(cost2,a.at(0)+b.at(0)) << endl;
}