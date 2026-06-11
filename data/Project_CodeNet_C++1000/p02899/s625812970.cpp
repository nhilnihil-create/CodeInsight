#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, buf;
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> A;
    for(int i = 1; i <= N; ++i){
        cin >> buf;
        A.push(make_pair(buf, i));
    }
    while(!A.empty()){
        cout << A.top().second << ' ';
        A.pop();
    }
    cout << endl;
    return 0;
}