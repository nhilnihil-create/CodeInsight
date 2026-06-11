#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> X(N);
    int sum=0;
    for(int i=0; i<N; i++){
        cin >> X.at(i);
        sum=sum+X.at(i);
    }
    int P=sum/N;
    int ans1=0;
    for(int i=0; i<N; i++){
        ans1=ans1+(X.at(i)-P)*(X.at(i)-P);
    }
    int ans2=0;
    P=P+1;
    for(int i=0; i<N; i++){
        ans2=ans2+(X.at(i)-P)*(X.at(i)-P);
    }
    cout << min(ans1,ans2) << endl;
}
