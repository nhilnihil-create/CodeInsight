#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    vector<int> height(N);
    vector<int> most_high(N);
    for(int i=0;i<N;i++){
        cin >> height.at(i);
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        most_high.at(a-1)=max(most_high.at(a-1),height.at(b-1));
        most_high.at(b-1)=max(most_high.at(b-1),height.at(a-1));
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(height.at(i)>most_high.at(i))  ans++; 
    }
    cout << ans;
}