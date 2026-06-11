#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long long> D(N);
    for(int i=0;i<N;++i)cin>>D[i];
    sort(D.begin(),D.end());
    long long left = D[N/2-1];
    long long right = D[N/2];
    cout<<right - left<<endl;
}